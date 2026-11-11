#include <bits/stdc++.h>
using namespace std;
int ans[4];
struct node {
	int cx;
	string zw;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	node x,m;
	cin>>x.cx>>x.zw>>m.cx>>m.zw;
	if (x.cx==m.cx){
		ans[0]=1;
	}else{
		cout<<0<<0<<0<<0<<endl;
		return 0;
	}
	if (x.zw[0]==m.zw[0] && x.zw[1]==m.zw[1]){
		ans[1]=1;
	}else{
		cout<<1<<0<<0<<0<<endl;
		return 0;
	}
	char xm=x.zw[2];
	char mm=m.zw[2];
	if (xm=='A' || xm=='B' || xm=='C'){
		if (mm=='A' || mm=='B' || mm=='C'){
			ans[2]=1;
		}
		else{
			cout<<1<<1<<0<<0;
			return 0;
		}
	}else{
		if (mm=='D' || mm=='E'){
			ans[2]=1;
		}else{
			cout<<1<<1<<0<<0;
			return 0;
		}
	}
	if (abs(xm-mm)==1 && !(xm=='C' && mm=='D') && !(xm=='D' && mm=='C')){
		ans[3]=1;
	}else{
		cout<<1<<1<<1<<0;
		return 0;
	}
	for (int i=0;i<4;i++){
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
} 
