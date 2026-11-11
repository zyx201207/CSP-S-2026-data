#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e;
int w[100005];
int main(){
	//freopen("trave.in","r",stdin);
	//freopen("trave.out","w",stdout);
	cin>>a>>b>>c>>d;
	while(w[a]==w[c]){
		if(w[b]-w[d]==1){
			cout<<"1111";
			break;
		}
		if(w[d]-w[b]==1){
			cout<<"1111";
			break;
		}
		if(w[b]-w[d]!=1){
			cout<<"1110";
			break;
		}
		
		else{
			cout<<"0000";
		}
		
		}
		
		return 0;
	}
	
		

