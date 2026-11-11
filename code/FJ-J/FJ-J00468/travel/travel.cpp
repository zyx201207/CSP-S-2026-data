#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y;
	string x1,y1;
	cin>>x>>x1>>y>>y1;
	char a1=x1[0],a2=x1[1],a3=x1[2];
	char b1=y1[0],b2=y1[1],b3=y1[2];
	int p=a3-'A'+1,q=b3-'A'+1;
	string s1,s2;
	s1[0]=a1;
	s1[1]=a2;
	s2[0]=b1;
	s2[1]=b2;
	if(x==y){
		cout<<"1";
		if(s1==s2&&a2==b2){
			cout<<"1";
			if((a3<='C'&&b3<='C')||(a3>='D'&&b3>='D')){
				cout<<"1";
				if(abs(p-q)==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else
		cout<<"0000";
	return 0;
}
