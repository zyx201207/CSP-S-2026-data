#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0; 
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	int s=b[2]-'A'+1,bb=d[2]-'A'+1;
	if((s<=3&&bb<=3)||(s>3&&bb>3)){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if(s>3||(s==1&&bb==2)||(s==2&&(bb=1||bb==3))||(s==3&&bb==2)){
		cout<<1;
	}else cout<<0;
	return 0;
} 
