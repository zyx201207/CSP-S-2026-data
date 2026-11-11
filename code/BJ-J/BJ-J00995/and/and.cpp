#include<bits/stdc++.h>
using namespace std;
long long n,m,a[20005],sum;
bool b[20005];
long long x,y;
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n+1-m;i++){
		for(long long j=i+1;j<=n;j++){
			if((a[i]&a[j])>=sum){
				sum=(a[i]&a[j]);
				x=i;
				y=j;
			}
		}
	}
	b[x]=1;
	b[y]=1;
	if(m>=3){
		for(long long p=3;p<=m;p++){
			int ans,pp;
			for(long long j=1;j<=n;j++){
				if(b[j]==0){
					ans=sum&b[j];
					pp=sum;
					x=j;
				}
			}
			for(long long i=x+1;i<=n;i++){
				if(b[i]==0&&(pp&a[i])>=ans){
					ans=(pp&a[i]);
					x=i;
				}
			}
			b[x]=1;
			sum=sum&a[x];
		}
	}
	cout<<sum;
	return 0;
}