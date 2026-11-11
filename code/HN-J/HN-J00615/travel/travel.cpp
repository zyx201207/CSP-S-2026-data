#include<bits/stdc++.h>
using namespace std;
string a[10];
long long num,sum;
bool flag=false,check=false,k=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i=1;i<=4;i++)cin>>a[i];
	if(a[1]==a[3]){
		cout<<1;
		k=true;
	}
	else cout<<0; 
	string s_first=a[2],s_second=a[4];
	int x=(s_first[0]-'0')*10+(s_first[1]-'0');
	int y=(s_second[0]-'0')*10+(s_second[1]-'0');
	if(x==y&&k){
		cout<<1;
		flag=true;
	}
	else cout<<0;
	x=s_first[2],y=s_second[2];
	if(x>='A'&&x<='C')num=1;
	if(y>='A'&&y<='C')sum=1;
	if(num==sum&&flag){
		cout<<1;
		check=true;
	}
	else cout<<0;
	int h=(x-'A')-(y-'A');
	if(check&&abs(h)==1)cout<<1;
	else cout<<0;
	cout<<"\n";
	return 0;
}
