#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[500010],cha[500010],sum[500010],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0) flag=0;
	}
	if(flag==0){
		int b=abs(a[1]-0);
		for(int i=1;i<=n;i++) a[i]+=b+1;
	}
	for(int i=1;i<=n;i++){
		
		cha[i]=a[i]-a[i-1];
		sum[i]=(cha[i]*(i-1))+sum[i-1];
		
	}
	for(int i=1;i<=n;i++){
		if(sum[i]>m){
			cout<<(i-1);
			return 0;
		}	
	}
	cout<<n;
	return 0;
}
