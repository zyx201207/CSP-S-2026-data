#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	if(m==1){
		while(n--){
			if((n+1)%2==1){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
