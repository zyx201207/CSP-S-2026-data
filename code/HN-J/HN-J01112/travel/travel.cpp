#include <bits/stdc++.h>
using namespace std;
const char ch[5]={'A','B','C','D','F'};
string a,b;
string cr,sr,cx,sx;//c:che s:zuowei
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx) cout<<"1";
	else cout<<"0";
	a=sr[0]+sr[1],b=sx[0]+sx[1];
	if(cr==cx&&a==b) cout<<"1";
	else cout<<"0";
	if(cr==cx&&a==b){
		if('A'<=sr[2]&&sr[2]<='C'&&'A'<=sx[2]&&sx[2]<='C')
			cout<<"1";
		else if('D'<=sr[2]&&sr[2]<='F'&&'D'<=sx[2]&&sx[2]<='F')
			cout<<"1";
		else
			cout<<"0"; 
	}else cout<<"0";
	if(cr==cx&&a==b){
		bool flag=0;
		for(int i=0;i<=4;i++)
			for(int j=0;j<=4;j++){
				if(i==2&&j==3) continue;
				if(i==3&&j==2) continue;
				if(ch[i]==sr[2]&&ch[j]==sx[2]&&abs(i-j)<=1)
					flag=1;
			}
		if(flag) cout<<"1";
		else cout<<"0";
	}else cout<<"0";
	return 0;
}
