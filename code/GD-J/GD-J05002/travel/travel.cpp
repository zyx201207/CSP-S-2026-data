#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){//1
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s1[1]){//2
			cout<<1;
			int a=s1[2]-'A',b=s2[2]-'A';
			
			if(a>=3&&b>=3){//3
				cout<<1<<1;
			}else if(a<3&&b<3){//3
				cout<<1;
				if(b-a==1){
					cout<<1;
				}else if(a==2&&b==3){
					cout<<0;
				}else{
					cout<<0;
				}
			}
			else{//3
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	
	
	
}
