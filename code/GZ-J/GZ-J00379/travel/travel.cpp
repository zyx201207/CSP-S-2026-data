//GZ-J00379 兴义市弘毅中学 刘俊池 
#include <bits/stdc++.h>
using namespace std;
long long x1,x2,p1,p2;
char s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>p1>>s1>>x2>>p2>>s2;
	if(x1==x2){
		cout<<1;
		if(p1==p2){
			cout<<1;
			if(s1<='C'&&s2<='C'||s1>='D'&&s2>='D'){
				cout<<1;
				if(s1-s2==1||s1-s2==-1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
