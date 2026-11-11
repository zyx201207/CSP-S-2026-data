#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);cout.tie(0);
	int a,b;string aa,bb;
	cin>>a>>aa>>b>>bb;
	int c=(aa[0]-'0')*10+(aa[1]-'0'),d=(bb[0]-'0')*10+(bb[1]-'0');
	if(a==b){
		cout<<1;
		if(c==d){
			cout<<1;
			if((float(int(aa[2]))-(int('A')+2.5))*(float(int(bb[2]))-(int('A')+2.5))>0){
				cout<<1;
				if(abs(aa[2]-bb[2])==1||min(int(aa[2]),int(bb[2]))>'C') cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
