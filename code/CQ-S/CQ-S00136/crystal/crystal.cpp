#include<bits/stdc++.h>
using namespace std;
int n,l,mx;
long long m,a[500005],b[500005],cnt,e;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i=n;i>=1;i--){
		cnt=0;
		e=0;
		l=0;
		for(int j=i;j>=1&&cnt<=m;j--){
			cnt=cnt+e+b[j];
			e+=b[j];
			l++;
		}
		mx=max(l,mx);
	}
	cout<<mx;
	return 0;
}

