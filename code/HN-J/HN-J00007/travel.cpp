#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,e;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>a>>c>>b>>d;
	if(a==b){
		e+=1;
		int f=1;
		if(c.size()==d.size()){
			for(int i=0;i<c.size()-1;i++){
				if(c[i]!=d[i]){
					f=0;
				}
			}
		}else{
			f=0;
		}
		if(f){
			if((c[c.size()-1]>='A'&&c[c.size()-1]<='C')||(c[c.size()-1]=='D'&&d[d.size()-1]=='E')){
				if((c[c.size()-1]=='A'&&d[d.size()-1]=='B')||(c[c.size()-1]=='B'&&d[d.size()-1]=='C')||(c[c.size()-1]=='D'&&d[d.size()-1]=='E')){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
