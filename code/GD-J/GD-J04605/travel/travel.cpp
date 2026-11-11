#include<iostream>
#include<cmath>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
  	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a;
	cin>>c;
	cin>>b;
	cin>>d;
	if(a==b){
		cout<<1;
		if(int(c[0])+int(c[1])==int(d[0])+int(d[1])){
			cout<<1;
			if((int(c[2])<=67&&int(d[2])<=67)||(int(c[2])>67&&int(d[2])>67)){
				cout<<1;
				if((abs(int(c[2])-int(d[2]))==1)||(int(c[2])==68&&int(d[2])==70)||(int(c[2])==70&&int(d[2])==68)){
					cout<<1;
				}else cout<<0;
			}else cout<<0<<0;
		}else cout<<0<<0<<0;
		
	}else cout<<0<<0<<0<<0;
	return 0;
} 
