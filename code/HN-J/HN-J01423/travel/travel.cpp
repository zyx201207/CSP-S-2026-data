#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,a1,b,b1;
	cin>>a>>a1>>b>>b1;
	int x,y,z,k;
	
	for(int i=1;i<=1001;i++){
		
		if(a==b&&a[i]!=1&&a[i]!=16&&b[i]!=1&&b[i]!=16){
			x=1;
		}else x=0;
		if(a==b&&a[i]!=1&&a[i]!=16&&b[i]!=1&&b[1]!=16&&a[i]>='A'&&a[i]<='C'&&b[i]>='A'&&b[i]<='C'||a[i]>='D'&&a[i]<='E'&&b[i]>='D'&&b[i]<='E'){
			z=0;
		}else z=1;
		if(a1[i]=='A'&&b1[i]=='B'||a1[i]=='B'&&b1[i]=='A'||a1[i]=='B'&&b1[i]=='C'||a1[i]=='C'&&b1[i]=='B'||a1[i]=='D'&&b1[i]=='E'||a1[i]=='E'&&b1[i]=='D'){
			k=1;
		}else k=0;
		
	
	}
	for(long long i=1;i<=18;i++){
		if(a[i]==b[i]){
			y=1;
		}else y=0;
	}
	cout<<x<<y<<z<<k;
	return 0;
}
