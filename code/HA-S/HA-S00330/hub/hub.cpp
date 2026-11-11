#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(t==1){
		cout<<1;
		return 0;
	}
	if(t==2){
		cout<<1<<endl;
		cout<<2<<endl;
		return 0;
	}
	if(t>2){
		for(int i=1;i<=t-2;i++){
			cout<<1<<endl;
		}
		cout<<1<<endl;
		cout<<2<<endl;
		return 0;
	}
	return 0;
}

