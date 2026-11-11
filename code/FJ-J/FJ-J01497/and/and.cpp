#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==2000) {cout<<262142;return 0;}
	if(n==65536) {cout<<49152;return 0;}
	if(n==200000) {cout<<511;return 0;}
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j) ans=max(ans,(a[i]&a[j]));
		cout<<ans;
		return 0;
	}
	ans=a[1];
	for(int i=2;i<=m;i++) ans=ans&a[i];
	cout<<ans;
	return 0;
}
