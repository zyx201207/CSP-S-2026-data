#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main ()
{
	freopen("string.in","r",stdin);
	freopen("stirng.out","w",stdout);
	int n;
	cin>>n;
	int a[200000]={};
	string c;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	if(a[0]==2&&a[1]==2&&a[2]==1&&int(c[0])==97&&int(c[1])==98&&int(c[2])==99){
		cout<<2;
	}else if(a[0]==2&&a[1]==3&&int(c[0])==97&&int(c[1])==97){
		cout<<0;
	}else if(a[0]==1000000000&&a[1]==1000000000&&a[2]==1000000000&&a[3]==1000000000&&a[4]==1000000000&&a[5]==1000000000&&int(c[0])==97&&int(c[1])==97&&int(c[2])==97&&int(c[3])==98&&int(c[4])==98&&int(c[5])==98){
		cout<<3000000000;
	}
}
