#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int a=stoi(c1);
	int b=stoi(c2);
	int c=0,d=0;
	char e=s1[2],f=s2[2];
	c=int(s1[0]-'0')*10+int(s1[1]-'0');
	d=int(s2[0]-'0')*10+int(s2[1]-'0');
	if(a==b){
		cout<<1;
		if(c==d){
			cout<<1;
			int e1=e-'C';
			int f1=f-'C';
			if((e1>0&&f1>0)||(e1<=0&&f1<=0)){
				cout<<1;
				if(e1-f1==1||e1-f1==-1){
					cout<<1;
				}else{
					cout<<0;
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
