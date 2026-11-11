#include<bits/stdc++.h>
using namespace std;
long long q,w;
string z,x,c,v;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin>>z>>x>>c>>v;
	if(z[0]!=c[0]||z[1]!=c[1]){
		cout<<"0000";
	}
	else{
		cout<<1;
		q=int(x[0]-'0')*10+int(x[1]-'0');
		w=int(v[0]-'0')*10+int(v[1]-'0');
		if(q!=w){
			cout<<"000";
		}	
		else{
			cout<<1;
			if((x[2]<='C'&&v[2]>='D')||(x[2]>='D'&&v[2]<='C')){
				cout<<"00";
			}
			else{
				cout<<1;
				if(x[2]+1==v[2]||x[2]-1==v[2]){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
		}
	}
	return 0;
}





