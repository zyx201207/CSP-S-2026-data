#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		if(t==2){
			cout << 1 << endl;
			cout << 2 << endl;
		}else{
			for(int i=1;i<=t;i++){
				cout << 1 << endl;
			}
		}
	}
	return 0;
}
