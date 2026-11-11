#include<bits/stdc++.h>
using namespace std;
int check(char a,char b){
	int x=a-'A'+1,y=b-'A'+1;
	if(x<=3&&y>3)return 0;
	if(x>3&&y<=3)return 0;
	if(x==1&&y==3)return 1;
	if(x==3&&y==1)return 1;
	return 2;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a,b,c,d,e,f,g,h,i,j;
	cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j;
	if(a==f&&b==g){
		if(c==h&&d==i){
			int k=check(e,j);
			if(k==0){
				cout<<"1100";
			}else if(k==1){
				cout<<"1110";
			}else{
				cout<<"1111";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
