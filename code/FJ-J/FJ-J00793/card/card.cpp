#include<bits/stdc++.h>
using namespace std;
long long b[100001],ans[3001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	bool f=true;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		if(a[i-1]>a[i]) f=false;
	}
	if(m==1){
		unsigned long long x=(n+1)*n/2;
		cout<<x;
		return 0;
	}
	if(f){
		for(int i=2;i<=m;i++) b[i]+=b[i-1];
		for(int i=1;i<=m;i++) cout<<b[i]+1<<" ";
		return 0;
	}
	bool v[3001];
	for(int i=1;i<=n;i++){
		memset(v,false,sizeof(v));
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				if(v[k]) continue;
				if(a[k]==a[j]){
					for(int z=k;z<j;z++) v[z]=true;
					break;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(!v[j]) ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
