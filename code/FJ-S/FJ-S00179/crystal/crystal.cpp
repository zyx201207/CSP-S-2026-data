#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],d,an,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d=0;
		an=0;
		int f[i+10];
		for(int j=1;j<=i;j++){
			f[j]=a[i]-a[j];
		}
		sort(f+1,f+i+1); 
		for(int j=1;j<=i;j++){
			d+=f[j];
			if(d<=m) an++;
		} 
		ans=max(an,ans);
	}
	cout<<ans;
	return 0;
} 
