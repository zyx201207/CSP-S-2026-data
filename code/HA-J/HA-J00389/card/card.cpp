#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
long long p[500010],t;
long long sum[300010];
long long han(long long x){
	for(long long i=1;i<=t;i++){
		if(p[i]==x){
			return i;
		}
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			p[j]=0;
		}
		t=0;
		for(long long j=i;j<=n;j++){
			long long g=han(a[j]);
			if(g!=0){
				long long q=t;
				for(long long k=g;k<=q;k++){
					p[k]==0;
					t--;
				}
				t++;
				p[t]=a[j];
			}else if(g==0){
				t++;
				p[t]=a[j];
			}
		}
		for(long long j=1;j<=m;j++){
			if(han(j)){
				sum[j]++;
			}
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}
