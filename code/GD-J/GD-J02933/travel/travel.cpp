#include<bits/stdc++.h>
using namespace std;
int a,b;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a!=b){
		cout<<"0000";
	}else{
		cout<<1;
		int c1=0,c2=0;
		c1=(s1[0]-'0')*10+(s1[1]-'0'),c2=(s2[0]-'0')*10+(s2[1]-'0');
		if(c1!=c2){
			cout<<"000";
		}else{
			cout<<1;
			int w1=s1[2]-'A',w2=s2[2]-'A';
			if(w1>=0&&w1<=2&&w2>=0&&w2<=2){
				cout<<1;
				if(abs(w1-w2)==2) cout<<0;
				else cout<<1;
			}else if(w1>=3&&w1<=4&&w2>=3&&w2<=4){
				if(w1==w2) cout<<0;
				else cout<<1;
			}else{
				cout<<"00";
			}
		}
	}
	return 0;
}
