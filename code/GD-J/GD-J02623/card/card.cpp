#include<bits/stdc++.h>
using namespace std;
int a[500010],f[500010],sum[300010],r[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		r[a[i]]=max(r[a[i]],i);
	}
	for(int i=1;i<=n;i++){
		f[i]++;
		if(i==r[a[i]]){
			f[i+1]+=f[i];
			sum[a[i]]+=f[i];
		}
		else{
			f[r[a[i]]]+=f[i]; 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
