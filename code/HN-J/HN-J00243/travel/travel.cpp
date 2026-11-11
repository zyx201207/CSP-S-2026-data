#include<bits/stdc++.h>
using namespace std;
string a,b;
int n,m,x,y,i,j;
char c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>m>>b;
	if(n!=m){
		cout<<"0000"<<endl;
	}else{
		x=a[0]-'0';
		x*=10;
		x+=a[1]-'0';
		y=b[0]-'0';
		y*=10;
		y+=b[1]-'0';
		if(x!=y){
			cout<<"1000"<<endl;
		}else{
			i=a[2]-'A'+1;
			j=b[2]-'A'+1;
			if(1<=i&&1<=j&&i<=3&&j<=3){
				if(i==1){
					if(j==2)cout<<"1111"<<endl;
					else cout<<"1110"<<endl;
				}else if(i==3){
					if(j==2)cout<<"1111"<<endl;
					else cout<<"1110"<<endl;
				}else cout<<"1111"<<endl;
			}else if(4<=i&&4<=j&&i<=5&&j<=5){
				cout<<"1111"<<endl;
			}else{
				cout<<"1100"<<endl;
			}
		}
	}
	return 0;
}
