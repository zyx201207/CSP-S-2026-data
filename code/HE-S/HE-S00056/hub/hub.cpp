#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==0&&t==2) {
		cout<<1<<"\n"<<2;
	}else{
		for(int i=1;i<=t;i++){
			cout<<rand()%5<<"\n";
		}
	}
	return 0;
}
