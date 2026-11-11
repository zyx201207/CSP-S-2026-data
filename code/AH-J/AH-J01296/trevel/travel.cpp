#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdin);
    int c1,c2,d1,d2;
    char e1,e2;
    cin>>c1>>d1>>e1>>c2>>d2>>e2;
    if(e1>e2){
		swap(e1,e2);
	}
    if(c1!=c2){
		cout<<"0000";
	}else if(d1!=d2){
		cout<<"1000";
	}else if(e1=='A'){
		if(e2=='B'){
			cout<<"1111";
		}else if(e2=='C'){
			cout<<"1110";
		}else{
			cout<<"1100";
		}
	}else if(e1=='B'){
		if(e2=='C'){
			cout<<"1111";
		}else{
			cout<<"1100";
		}
	}else if(e1=='C'){
		
		cout<<"1100";
		
	}else{
		
		cout<<"1111";
		
	}
	//ab bc df
    return 0;
}
