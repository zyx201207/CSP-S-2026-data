#include<bits/stdc++.h>
using namespace std;

string a;
string b[4];
bool a1,a2,a3,a4;

void aaa(){
	if(b[0]==b[2]){
		a1=true;
		for(int i=0;i<=1;i++){
			if(b[1][i]!=b[3][i]){
				return ;
			}
		}
		a2=true;
		int x=(int)(b[1][2]-'A'+1),y=(int)(b[3][2]-'A'+1);
		if(x<=3&&y<=3){
			a3=true;
			if(x-y==1||x-y==-1) a4=true;
			return ;
		}
		if(x>=4&&y>=4){
			a3==true;
			if(x-y==1||x-y==-1) a4=true;
			return ;
		}
		
	}
} 

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>b[0]>>b[1]>>b[2]>>b[3];
	aaa(); 
	cout<<a1<<a2<<a3<<a4;
}
