#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
string c[10],r[10];
map<char,int> v;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	v['A']=v['B']=v['C']=1;
	v['D']=v['E']=2;
	for(int i=1;i<=2;i++)cin>>r[i]>>c[i];
	if(r[1]==r[2]){
		cout<<1;
		if(c[1][0]==c[2][0]&&c[1][1]==c[2][1]){
			cout<<1;
			if(v[c[1][2]]==v[c[2][2]]){
				cout<<1;
				if(v[c[1][2]]==2||(c[1][2]=='B'||c[2][2]=='B'))cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}

