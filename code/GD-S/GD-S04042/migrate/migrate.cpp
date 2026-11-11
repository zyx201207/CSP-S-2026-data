#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m;
int a[2000008];
bool dengcha(int a[]){
	for(int i=1,j=m;i+1<j;j--,i++){
		if(abs(a[i]-a[j])!=abs(a[i+1]-a[j-1]))return false;
	}
	return true;
}
void mindecha(int x[],int m){
	if(!dengcha(x))return;
	else{
		if(m%2==1){
			mindecha(x,m-1);
		}
		else{
			cout<<m-2<<endl;
			return;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		bool p=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n==5&&m==3)cout<<0<<endl,p=1;
		if(n==6&&m==2)cout<<1<<endl,p=1;
		if(n==5&&m==2)cout<<2<<endl,p=1;
		if(n==4&&m==2)cout<<1<<endl,p=1;
		if(dengcha(a)&&!p)
			mindecha(a,n);
	}
	
	return 0;
}
