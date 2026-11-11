#include<bits/stdc++.h>
using namespace std;
long long a[500020];
long long b[500030][10];
long long c[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;i<=n;j++){
			if(b[a[j]][1]==1){
				for(long long k=b[a[j]][2];k<=j;k++){
					b[c[k]][1]=0;
				}
			}
			b[a[j]][1]=1;
			b[a[j]][2]=j;
			for(long long k=i;k<=j;k++){
				if(b[k][1]==1){
					b[k][3]++;}
			}
		}
	}
	for(long long i=1;i<=n;i++){
		cout<<b[i][3];}
	return 0;
}
