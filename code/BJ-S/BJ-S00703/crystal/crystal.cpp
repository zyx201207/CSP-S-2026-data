#include<bits/stdc++.h>
using namespace std;
int n;
int a[5001000],cf[5001000];
int m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cf[1]=0;
	for(int i=2;i<=n;i++){
		cf[i]=cf[i-1]+a[i]-a[i-1];
	}
	cout<<endl;
	int num=0,cha=0,zd=0;
	for(int i=2;i<=n;i++){
		num+=1;
		cha=cha+(cf[i]-cf[i-1])*num;
		while(cha>m){
			num-=1;
			cha=cha-(cf[i]-cf[i-num]);
		}
		if(num>zd) zd=num;
	}
	cout<<zd+1;
	return 0;
}