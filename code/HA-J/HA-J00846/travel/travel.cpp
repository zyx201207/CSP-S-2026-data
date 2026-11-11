#include<bits/stdc++.h>
using namespace std;
string a,b,x,y;
bool q;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>y;
	if(a==x){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		if(b[i]==y[i]){
			q=1;
		}else{
			q=0;
		}
	}
	if(q==1){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(b[2]>='A'&&b[2]<='C'&&y[2]>='A'&&y[2]<='C'){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(b[2]>='D'&&b[2]<='E'&&y[2]>='D'&&y[2]<='E'){
		cout<<"11";
		return 0;
	}
	int w=(int)b[2],e=(int)y[2];
	if(max(w,e)-min(w,e)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
