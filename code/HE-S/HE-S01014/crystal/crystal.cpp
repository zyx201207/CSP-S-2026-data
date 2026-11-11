#include <bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
int n,m;
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long a[N],ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(a[N]==a[N]){
		cout<<n<<endl;
		return 0;
	}
    for(long long j=1;j<=m;j++){
    	 if(a[0]!=a[2]){
			a[0]++;
			m--;
		}
		 if(a[1]!=a[2]){
			a[1]++;
			m--;
		}
	}
	for(long long i=0;i<n;i++){
		if(a[i]==a[2]){
			ans++;
		}
	}
	cout<<ans+1<<endl;
	return 0;
}

