#include <bits/stdc++.h>
using namespace std;

const int N=5*10e5;
long long n,m,a[N],sum;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(long long i=1;i<=n-1;i++){
		if(a[i]!=a[i+1]){
			m=(m-(a[i+1]-a[i]))*i;
			a[i]=a[i+1];
			if(m>=0){
				sum+=1;
			}
		}
	}
	
	cout<<sum;
	
	return 0;
}

