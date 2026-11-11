#include<bits/stdc++.h>
using namespace std;
struct p{
	int c,s,t,f;
};
p a[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ans="00000";
	for(int i=1;i<=2;i++){
		string x;
		cin>>x;
		a[i].c=stoi(x);
		string y;
		cin>>y;
		a[i].s=(y[0]-'0')*10+(y[1]-'0');
		char z=y[2];
		a[i].t=int(z-'A')+1;
		if(a[i].t>=1 and a[i].t<=3){
			a[i].f=1;
		}
		else{
			a[i].f=2;
		}
    }
	if(a[1].c==a[2].c){
		ans[1]='1';
		if(a[1].s==a[2].s){
			ans[2]='1';
			if(a[1].f==a[2].f){
				ans[3]='1';
				if(abs(a[1].t-a[2].t)==1){
					ans[4]='1';
				}
			}
		}
	}
	for(int i=1;i<=4;i++){
		cout<<ans[i];
	}
	return 0;
}
