#include<bits/stdc++.h>
using namespace std;
char x[5]={'A','B','C'},y[5]={'D','E'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int fg=0;
	if(a==c){
		cout<<1;
		fg=1;
	}else{
		cout<<0;
		fg=0;
	}
	if((b[0]-'0')*10+b[1]-'0'==(d[0]-'0')*10+d[1]-'0'&&fg==1){
		cout<<1;
		fg=1;
	}else{
		cout<<0;
		fg=0;
	}
	int flag1=0,flag2=0;
	for(int i=0;i<=2;i++){
		if(b[2]==x[i]){
			flag1=1;
		}
	}
	for(int i=0;i<=2;i++){
		if(d[2]==x[i]){
			flag2=1;
		}
	}
	if(flag1==flag2&&fg==1){
		cout<<1;
	}else{
		cout<<0;
		fg=0;
	}
	if(abs(d[2]-b[2])==1&&max(d[2],b[2])!='D'&&fg==1){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
