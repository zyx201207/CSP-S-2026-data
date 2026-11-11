#include<bits/stdc++.h>
using namespace std;
bool l[6005];
long long a[6005];
long long ans[6005];
long long v[5055][5055];
long long b[6005]; 
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
	} 
	for(long long i=n;i>=1;i--){
		for(long long j=1;j<=n;j++)
			v[j][i]=v[j][i+1];
		v[a[i]][i]++;
	}
	for(long long k=1;k<=n;k++){
		for(long long i=1;i<=m;i++)
			l[i]=true;
		for(long long i=k;i<=n;i++){
			if(v[a[i]][i]==1){
				if(l[a[i]]==true)
					ans[a[i]]++;
				l[a[i]]=false;
			}
			else
				i=b[a[i]]-1;
		}
	}
	for(long long i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
