#include<bits/stdc++.h>
using namespace std;
bool flag=0,f=0;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	a=int(s1[0]-'0')*10+int(s1[1]-'0');
	b=int(s2[0]-'0')*10+int(s2[1]-'0');
	c=int(s1[2]-'A'+1);
	d=int(s2[2]-'A'+1);
	if(a==b){
		f=1;
		cout<<"1";
	}
	else cout<<"0";
	if(((c>=1&&c<=3&&d>=1&&d<=3)||(c>=4&&c<=5&&d>=4&&d<=5))&&f==1){
		flag=1;
		cout<<"1";
	}
	else cout<<"0";
	if(flag==1&&a==b&&(c+1==d||c-1==d)){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
