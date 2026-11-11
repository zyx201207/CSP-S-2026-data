#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
long long a=0,b=0,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	c=int(s1[2])-64;
	d=int(s2[2])-64;
	if(c1==c2){
		cout<<1;
		for(int i=0;i<2;i++){
			a*=10;
			a+=(s1[i]-'0');
			b*=10;
			b+=(s2[i]-'0');
		}
		if(a==b){
			cout<<1;
			if((c<=3&&d<=3)||(c>=4&&d>=4)){
				cout<<1;
				if(abs(c-d)==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
