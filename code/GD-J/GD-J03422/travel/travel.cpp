#include<bits/stdc++.h>
using namespace std;
int a,b,t1,t2;
string c,d;
bool a1,a2,a3,a4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a>>c>>b>>d;
	if(a==b){
		a1=true;
		if(c[0]==d[0]&&c[1]==d[1]){
			a2=true;
			if(c[2]<='C'&&d[2]<='C'||c[2]>'C'&&d[2]>'C'){
				a3=true;
				if(c[2]<='C'&&(c[2]+1==d[2]||c[2]-1==d[2])){
					a4=true;
				}else if(c[2]>'C'&&(c[2]+2==d[2]||c[2]-2==d[2])){
					a4=true;
				}
			}
		}
	}
	
	cout<<a1<<a2<<a3<<a4<<endl;
	return 0;
}
