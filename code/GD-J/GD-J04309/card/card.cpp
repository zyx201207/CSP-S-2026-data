#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],f[500005],s[500005],p[300005],ans[300005],aans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=i;
	}
	for(int i=n;i>=1;i--){
		if(p[a[i]]) f[i]=p[a[i]];
		p[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			while(j!=f[j])j=f[j];
			aans[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			ans[j]+=aans[j];
			aans[j]=0;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	
	
	return 0;
} 
