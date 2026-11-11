#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],f[500010],d[500010],s[500010],ans[500010];
int fq(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=fq(f[x]);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=i;
		d[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		f[i]=d[a[i]];
		s[d[a[i]]]++;
	}
	for(int i=1;i<=n;i++){
		if(s[i]){
			ans[a[i]]+=s[i];
			int z=fq(i+1);
			s[z]+=s[i]; 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
