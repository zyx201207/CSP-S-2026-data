#include<bits/stdc++.h>
using namespace std;
typedef string ll;
ll x,r;
ll x1,r1;
int cnt=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>r1;
	cin>>x>>x1;
	if(r==x){
		cout<<1;
		for(int i=0;i<2;i++){
			if(r1[i]==x1[i]){
				cnt++;
			}
		}
		if(cnt==2){
			cout<<1;
			if((r1[2]>='A'&&r1[2]<='C'&&x1[2]>='A'&&x1[2]<='C')||(r1[2]>='D'&&r1[2]<='F'&&x1[2]>='D'&&x1[2]<='F')){
				cout<<1;
				if(r1[2]+1==x1[2]||x1[2]+1==r1[2]){
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;
				}
			}else{
				cout<<"00";
			}
				return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
