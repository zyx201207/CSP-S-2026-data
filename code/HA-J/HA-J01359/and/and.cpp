#include<bits/stdc++.h>
using namespace std;

long long n,m,a[200005],ans,j,sum,cnt,id;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for (long long i=0;i<(1<<n);i++){
		j=i;
		sum=(long long)(2e20-1);
		cnt=0;
		id=1;
		while(j){
			if(j&1==1){
				cnt++;
				sum&=a[id];
			}
			j/=2;
			id++;
		}
		if(cnt==m){
			ans=max(ans,sum);
		}
	}
	
	cout<<ans;
	
	
	return 0;
}