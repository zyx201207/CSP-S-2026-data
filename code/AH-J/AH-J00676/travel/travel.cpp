#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool f[305];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	f['A']=1;
	f['B']=1;
	f['C']=1;
	f['D']=0;
	f['F']=0;
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			if(f[int(b[2])]==f[int(d[2])]){
				cout<<1;
				if(b[2]-1==d[2]||b[2]+1==d[2])cout<<1;
				else cout<<0;
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
