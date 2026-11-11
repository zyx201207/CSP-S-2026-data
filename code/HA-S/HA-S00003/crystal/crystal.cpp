#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a=0;
	cin>>n>>m;
	long long a[n];
	for(long long i=0;i<n;i++){
	    cin>>a[i];
		if(a[i]!=a[ceil(n/2)]||a[i]==a[ceil(n/2)]){
			a[i]=ceil(n/2);
			a++;
		}
	}
	cout<<a;
	return 0;
}