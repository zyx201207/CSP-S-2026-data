#include<bits/stdc++.h> 
using namespace std;
struct str{
	long shu;
	char zimu;
};
long n,all=0;
long ans=0;
str a[1000000];
str a1[1000000];
int main(){
	freopen("sring.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].shu>>a[i].zimu;
		
	}
	for(int i=1;i<=n;i++){
		a1[i].shu=a[n-i+1].shu;
		a1[i].zimu=a[n-i+1].zimu;
	}
	for(int i=1;i<=n;i++){
		if(a[i].zimu!=a1[i].zimu){
			ans+=abs(a[i].shu-a1[i].shu);
			if(a[i].shu==a1[i].shu){
				ans+=a[i].shu;
				
			}
		}
	}
	cout<<ans/2;
	return 0;
}
 

