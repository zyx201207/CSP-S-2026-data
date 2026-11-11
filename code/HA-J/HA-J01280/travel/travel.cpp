#include<bits/stdc++.h>
using namespace std;
char e[5]={'A','B','C','D','E'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<"1";
		int s,t;
		for(int i=0;i<5;i++){
			if(b[2]==e[i]){
				s=i;
			}
			if(d[2]==e[i]){
				t=i;
			}
		}
		int n,m;
        n=max(s,t);
        m=min(s,t);
		if(n<=2||m>2){
			cout<<"1";
			if(m+1==n){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"00";
		}
	}else{
		cout<<"000";
	}
	return 0;
}
