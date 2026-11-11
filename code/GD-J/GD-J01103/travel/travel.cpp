#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) {
		cout<<1;
		bool f=0;
		for(int i=0;i<b.size()-1;i++){
			if(b[i]!=d[i]) {
				f=1;
				break;
			}
		}
		if(f==0){
			cout<<1;
			if(b[b.size()-1]<='C'&&d[b.size()-1]<='C'||b[b.size()-1]>'C'&&d[b.size()-1]>'C')  {
				cout<<1;
				if(abs(b[b.size()-1]-d[b.size()-1])==1) cout<<1;
				else cout<<0;
			}
			else cout<<"00"; 
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
