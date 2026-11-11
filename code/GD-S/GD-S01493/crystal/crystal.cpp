#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	unsigned long long n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	unsigned long long sum=0;
	for(unsigned long long i=1;i<=100000000;i++){
		sum+=i;
		if(sum>m){
			cout<<i;
			break;
		}else if(sum==m){
			cout<<i+1;
			break;
		}
	}
	return 0;
} 
