#include<bits/stdc++.h>
using namespace std;
struct man{
	int a;
	int b;
	int c;
}x[2];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string q; 
	cin>>x[0].a;
	cin>>q;
	x[0].b=q[0]-'0'+q[1]-'0';
	x[0].c=int(q[2]-64);
	cin>>x[1].a;
	cin>>q;
	x[1].b=q[0]-'0'+q[1]-'0';
	x[1].c=int(q[2]-64);
	if(x[0].a!=x[1].a){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		if(x[0].b!=x[1].b){
			cout<<"000";
			return 0;
		}
		else{
			cout<<"1";
			if((x[0].c==4||x[0].c==5)&&(x[1].c==4||x[1].c==5)){
				cout<<"11";
				return 0;
			}else if((x[0].c==1||x[0].c==2||x[0].c==3)&&(x[1].c==1||x[1].c==2||x[1].c==3)){
				cout<<"1";
				if(max(x[0].c,x[1].c)-min(x[0].c,x[1].c)==1){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
					return 0;
				}
			}
			cout<<"00";
		}
	}
	
	
	cout<<x[0].a<<endl<<x[0].b<<x[0].c<<endl<<x[1].a<<endl<<x[1].b<<x[1].c;
	return 0;
} 










