#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	
	if(a==c){
		cout<<1;
		int o=(b[0]-'0')*10+b[1]-'0',o2=(d[0]-'0')*10+d[1]-'0';
		if(o==o2){
			cout<<1;
			int i1=b[2]-'A',i2=d[2]-'A';
			if((i1<=2&&i2<=2)||(i1>=3&&i2>=3)){
				cout<<1;

			}else cout<<0;
			
			if(max(i1,i2)-min(i1,i2)==1){
				cout<<1;
			}else{
				cout<<0;
			}			
			
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
	
}
