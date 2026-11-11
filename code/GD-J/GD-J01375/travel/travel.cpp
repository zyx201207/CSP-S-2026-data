#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<1;
		if(a2[0]==b2[0] and a2[1]==b2[1]){
			cout<<1;
			int f=1;
			if(min(a2[2],b2[2])>='A' and max(a2[2],b2[2])<='C'){
				cout<<1;
			}else if(min(a2[2],b2[2])=='D' and max(a2[2],b2[2])=='F'){
				cout<<1;
			}else{
				cout<<"00";
				f=0;
			}
			
			if(f==1){
				if( max(a2[2],b2[2])-min(a2[2],b2[2])==1 and min(a2[2],b2[2])!='C')
				cout<<1;
				else cout<<"0";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
