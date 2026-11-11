#include<bits/stdc++.h>
using namespace std;
int a,b;
string as,bs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	cin>>a>>as>>b>>bs;
	if(a==b){
		cout<<1;
		string p1=as,p2=bs;
		p1.erase(2); p2.erase(2);
		char l1=as[2],l2=bs[2];
		int c1,c2;
		if(l1=='F' || l1=='D') c1=1;
		else c1=2;
		if(l2=='F' || l2=='D') c2=1;
		else c2=2;
		if(p1==p2){
			cout<<1;
			if(c1==c2){
				cout<<1;
			}else{
				cout<<"0";
			}
			if((l1=='D' && l2=='F') || (l1=='F' && l2=='D') ||(abs((l1-'0')-(l2-'0'))==1 && ((l1!='D' && l2!='C') && (l1!='C' && l2!='D')))){
				cout<<1;
			}else{
				cout<<"0";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
