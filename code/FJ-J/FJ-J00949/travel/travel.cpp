#include<bits/stdc++.h>
using namespace std;
int c1,c2,s1,s2,x1,x2;
char a[10];
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>a[1]>>a[2]>>a[3]>>c2>>a[4]>>a[5]>>a[6];
	s1=(a[1]-'0')*10+(a[2]-'0');
	s2=(a[4]-'0')*10+(a[5]-'0');
	x1=a[3]-'A'+1;
	x2=a[6]-'A'+1;
	if(c1==c2){
		cout<<1;
		if(s1==s2){
			cout<<1;
			if((x1>=1&&x1<=3&&x2>=1&&x2<=3)||(x1>=4&&x1<=5&&x2>=4&&x2<=5)){
				cout<<1;
				if(x1-1==x2||x2-1==x1){
					cout<<1;
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
