#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	long long n,m,a[100000],max1=0,max2=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>max1){
			max2=max1;
			max1=a[i];
		}else if(a[i]>max2){
			max2=a[i];
		}
	}
	long long m1=0,m2=0,i=1,ans,an1;
	while(max1!=0){
		m1=m1+max1%2*i;
		max1/=2;
		i*=10;
	}
	i=1;
	while(max2!=0){
		m2=m2+max2%2*i;
		max2/=2; 
		i*=10;
	}
	cout<<m1&m2;
	return 0;
}
