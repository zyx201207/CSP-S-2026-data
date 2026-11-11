#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n,m;
	cin>>n>>m>>h;
	if(m==2){
		cout<<1<<" "<<2;
	}
	else if(m==3){
		cout<<1<<" "<<1<<" "<<2;
	}
	else{
		for(int i=1;i<=n;i++){
			int S;
			cout<<S%h;	
		}
	}
	return 0;
}

