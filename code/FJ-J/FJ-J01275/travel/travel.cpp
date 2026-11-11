#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
void solve(){
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			if((b[2]<='C'&&b[2]>='A'&&d[2]>='A'&&d[2]<='C')||(b[2]<='F'&&b[2]>='D'&&b[2]!='E'&&d[2]>='D'&&d[2]<='F'&&d[2]!='E')){
				cout<<1;
				if(abs(b[2]-d[2])==1&&b[2]+d[2]-'C'-'C'!=1){
					cout<<1;
				}else cout<<0;
			}else{
				for(int i=1;i<=2;i++){
					cout<<0;
				}
			}
		}else{
			for(int i=1;i<=3;i++){
				cout<<0;
			}
		}
	}else{
		for(int i=1;i<=4;i++){
			cout<<0;
		}
	}
	
}

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	solve();
	return 0;
}
