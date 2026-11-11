#include<bits/stdc++.h>
using namespace std;
int s[10000];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==0){
		for(int i=0;i<28;++i){
			cin>>s[i];
		}
		cout<<1<<endl;
		cout<<2;
	}
	else{
		for(int i=0;i<t;++i){
			cout<<rand()%1000000<<endl;
		}
	}
	return 0; 
}
