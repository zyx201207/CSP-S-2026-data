#include<iostream>
#include<cstring>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r,x;
	bool ans[8]={0};
	string rs,xs;
	cin>>r>>rs>>x>>xs;
	ans[1]=(r==x);
	ans[2]=(rs[0]==xs[0]&&rs[1]==xs[1]);
	switch(rs[2]){
		case 'A':
		case 'B':
		case 'C':
			ans[3]=(xs[2]>='A'&&xs[2]<='C');
			ans[4]=(rs[2]+1==xs[2]||rs[2]-1==xs[2]);
			break;
		case 'D':
		case 'F':
			ans[4]=(rs[2]+2==xs[2]||rs[2]-2==xs[2]);
			ans[3]=(xs[2]=='D'||xs[2]=='F');
	}
	bool flag=1;
	for(int i=1;i<=4;i++){
		if(flag){
			cout<<ans[i];
			flag=ans[i];
		}else{
			cout<<0;
		}
	}
	return 0;
} 
