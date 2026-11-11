#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int q,e;
	char w,r;
	cin>>n;
	if(n==1){
		cin>>q>>w;
		cout<<0<<endl;
	}else if(n==2){
		cin>>q>>w>>e>>r;
		if(w!=r){
		if(q>e) cout<<e<<endl;
		if(q<=e) cout<<q<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
}
