#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int f,t;
int n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	for(int i=0;i<2;i++)n=n*10+b[i]-'0';
	for(int i=0;i<2;i++)m=m*10+d[i]-'0';
	f=b[2]-'A'+1;
	t=d[2]-'A'+1;
	if(n!=m){
		cout<<"000";
		return 0;
	}else cout<<1;
	if(f>=4 && t>=4 )cout<<1;
	else if(f<=3 && t<=3)cout<<1;
	else {
		cout<<"00";
		return 0;
	}
	if(f>=4 and t>=4)cout<<1;
	else if(abs(f-t)<=1)cout<<1;
	else cout<<0;
	return 0;
}
