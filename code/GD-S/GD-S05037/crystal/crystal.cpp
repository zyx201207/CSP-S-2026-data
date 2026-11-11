#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,cnt,apn;
long long a[5000100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cnt=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	long long k=a[1]-a[0];
	for(int i=1;i<=n;i++){
	sum+=k*2;
	if(sum>m)
	if(sum-k>m){
	break;
	}else{
		apn++;
		break;
	}
	k+=k;
	apn+=2;	
	}
	cout<<apn+1;
	return 0;
}
