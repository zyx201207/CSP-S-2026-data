#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int MAXN=2e5+5;
int n,m;
int a[MAXN];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1]<<endl;return 0;
	}
	else if(m==n){
		int ans=a[1];
		for(int i=2;i<=m;i++){
			ans&=a[i];
		}
		cout<<ans<<endl;return 0;
	} 
	int ans=a[1];
	for (int i=2;i<=m;i++){
		if(ans&a[i]!=0)ans&=a[i];
		else i--;
	}
	cout<<ans<<endl;
	return 0;
}
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
