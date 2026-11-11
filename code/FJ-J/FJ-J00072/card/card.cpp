#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int an[N],n,s[N],m,ne,sf[N],c[N],mu[N],f[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=n;i>=0;i--){
		if(!sf[s[i]]){
			sf[s[i]]=i;
			f[i]=0;
		}
		else{
			f[i]=sf[s[i]];
		}
	}
	for(int i=1;i<=n;i++){
		c[i]+=c[i-1];
		if(f[i]){
			c[i+1]+=(i-c[i]);
			c[f[i]]-=(i-c[i]);
		}
	}
	for(int i=1;i<=n;i++){
		mu[i]=i-c[i];
		an[s[i]]+=mu[i]*(f[i]?0:1);
	}
	for(int i=1;i<=m;i++){
		cout<<an[i]<<' ';
	}
	return 0;
}