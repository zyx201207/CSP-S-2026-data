#include<bits/stdc++.h>
using namespace std;
char c1[3],c2[3],s1[4],s2[4];
int a=0,b=0,x=0,y=0,k,p=0,q=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=1;i++){
		a=a*10+s1[i]-48;
		b=b*10+s2[i]-48;
		p=p*10+c1[i]-48;
		q=q*10+c2[i]-48;
	}
	x=s1[2];
	y=s2[2];
	if(x>y) k=x-y;
	else k=y-x;
	if(p==q){
		if(a==b){
			if((x<='C'&&y<='C')||(x>'C'&&y>'C'))
			{
				if((x<='C'&&k==1)||(x>'C'&&y>'C')){
					cout<<"1111";
					return 0;
				}
				else
				{
					cout<<"1110";
					return 0;
				}
			}
			else{
				cout<<"1100";
				return 0;
			}
		}
		else{
			cout<<"1000";
			return 0;
		}
	}	
	else {
		cout<<"0000";
		return 0;
	}
	return 0; 
}
