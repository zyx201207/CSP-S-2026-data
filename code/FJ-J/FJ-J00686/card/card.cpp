#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500005];
long long now[300005][2];
long long n1[500005];
long long won,o;
long long sum[500005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		won=0;
		for(long long j=i;j<=n;j++){
			if(now[a[j]][0]!=0){
				o=won;
				won=now[a[j]][1];
				for(long long k=won;k<=o;k++){
					now[n1[k]][0]=0;
					now[n1[k]][1]=0;
				}
			}else{
				won++;
			}
			now[a[j]][0]=1;
			now[a[j]][1]=won;
			n1[won]=a[j];
		}
		for(long long i=1;i<=m;i++){
			if(now[i][0]){
				sum[i]++;
				now[i][0]=0;
				now[i][1]=0;
			}
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
