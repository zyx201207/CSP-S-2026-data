#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string aq,bq;
	cin>>a>>aq>>b>>bq;
	if(a==b){
		cout<<1;
		if(aq[0]==bq[0]&&aq[1]==bq[1]){
			cout<<1;
			if((aq[2]>='D'&&bq[2]>='D')||(aq[2]<'D'&&bq[2]<'D')){
				cout<<1;
				if(max(aq[2]-bq[2],bq[2]-aq[2])==1)cout<<1;
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}
