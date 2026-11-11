#include<bits/stdc++.h>
using namespace std;
struct{
	string id1,id2;
}a,b;
int ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a.id1>>a.id2;
	cin>>b.id1>>b.id2;
	if(a.id1==b.id1){
		cout<<1;
		if(a.id2.substr(0,2)==b.id2.substr(0,2)){
			cout<<1;
			if((a.id2[2]<'D'&&b.id2[2]<'D')||(a.id2[2]>='D'&&b.id2[2]>='D')){
				cout<<1;
				if(abs(a.id2[2]-b.id2[2])==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
