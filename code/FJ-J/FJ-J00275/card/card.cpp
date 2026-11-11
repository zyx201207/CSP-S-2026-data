#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],b[300005],t[500005];
long long p[300005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(b,0,sizeof(b));
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			t[j]=0;
		}
		long long now=0;
		for(long long j=i;j<=n;j++){
			bool find=1;
			if(now>0){
				for(long long k=1;k<=now;k++){
				if(t[k]==a[j]){
						now=k;
						find=0;
						break;
					}	
				}
			}
			if(find){
				now++;
				t[now]=a[j];
			}
		}
		for(long long j=1;j<=now;j++){
			if(t[j]!=0){
				b[t[j]]++;
			}
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}