#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m;cin>>n>>m;
	long long a[n];
	long long an[n];
	for(long long i=1;i<=n;++i){
		cin>>a[i];
		an[a[i]]=i;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		if(a[n]==1){
			cout<<n<<" "<<n-1;
			return 0;
		}
		if(a[n]==2){
			cout<<n-1<<" "<<n;
			return 0;
		}
	}
	if(m>=3){
		for(int i=1;i<=m;++i){
			cout<<an[i]<<" ";
		}
		return 0;
	}
	
}
