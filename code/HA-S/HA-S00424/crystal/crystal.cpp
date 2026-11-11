#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500005],i=0,sum=0,k=1,cha;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
//	for(int i=0;i<n;i++){
//		cout<<a[i]<<' ';
//	}
	if(m>=a[n-1]*n){
		cout<<n;
		return 0;
	}
	i=0;
	cha=a[1]-a[0];
	while(i<=m){
		i+=k*cha;
		k++;
		sum+=1;
	}
	if(sum>n){
		cout<<n;
	}else{
		cout<<sum;
	}
	
	return 0;
}

