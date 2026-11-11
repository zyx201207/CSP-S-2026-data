#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	long long a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
        cout<<1;
        if(b==d){
    		cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	
	
    

	return 0;
}

