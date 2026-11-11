#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,n1,m1;
	char n2,m2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>n1>>n2>>m>>m1>>m2;
	if(n==m)cout<<"1";
	else{
		for(int i=1;i<=4;i++)cout<<"0";
//		cout<<abs(int(n2)-int(m2))<<" "<<n2<<" "<<m2<<" "<<n<<" "<<m<<" "<<m1<<" "<<m2;
		return 0;
	}
	if(n1==m1)cout<<"1";
	else{
		for(int i=1;i<=3;i++)cout<<"0";
//		cout<<abs(int(n2)-int(m2))<<" "<<n2<<" "<<m2<<" "<<n<<" "<<m<<" "<<m1<<" "<<m2;
		return 0;
	}
	if(int(n2)-64+int(m2)-64<=4||int(n2)-64+int(m2)-64==10)cout<<"1";
	else{
		for(int i=1;i<=2;i++)cout<<"0";
//		cout<<abs(int(n2)-int(m2))<<" "<<n2<<" "<<m2<<" "<<n<<" "<<m<<" "<<m1<<" "<<m2;
		return 0;
	}if(abs(int(n2)-int(m2))==1||(abs(int(n2)-int(m2))==2&&int(n2)-64+int(m2)-64==10))cout<<"1";
	else {
		cout<<"0";
//		cout<<abs(int(n2)-int(m2))<<" "<<n2<<" "<<m2<<" "<<n<<" "<<m<<" "<<m1<<" "<<m2;
	}
	return 0;
} 
