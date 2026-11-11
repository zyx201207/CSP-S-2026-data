#include<bits/stdc++.h>
using namespace std;
long long o[500005],p[300005],l[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>o[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			bool u=0;
			for(long long k=1;k<=n;k++){
				if(l[k]==o[j]){
					u=1;
					l[k]=0;
				}
				if(u==1)l[k]=0;
			}
			l[j]=o[j];
		}
		for(long long j=1;j<=n;j++){
			p[l[j]]++;
		}
		for(long long j=1;j<=n;j++){
			l[j]=0;
		}
	}
	for(long long j=1;j<=m;j++){
		cout<<p[j]<<" ";
	}
	cout<<"\n";
	return 0;
}
