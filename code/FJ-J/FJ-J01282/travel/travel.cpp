#include <bits/stdc++.h>
#define int long long
#define fs(i,x,y) for(int i=x;i<=y;i++)
#define fd(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
void Bol(){
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int e=(b[0]-'0')+(b[1]-'0')*10;
	int f=(d[0]-'0')+(d[1]-'0')*10;
	char g=b[2],h=d[2];
	if(a==c){
		printf("1");
	}else{
		printf("0000");
		return ;
	}
	if(e==f){
		printf("1");
	}else{
		printf("000");
		return ;
	}
	if((g<='C'&&h<='C')||(g>='D'&&h>='D')){
		printf("1");
	}else{
		printf("00");
		return ;
	}
	if(abs(g-h)==1||(g=='D'&&h=='F')||(g=='F'&&h=='D')){
		printf("1");
	}else{
		printf("0");
		return ;
	}
}
int T;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	T=1;
	while(T--){
		Bol();
	}
	return 0;
}
