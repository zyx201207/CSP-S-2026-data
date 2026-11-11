#include<bits/stdc++.h>
using namespace std;
int b[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a;
    cin>>a;
    for(int i=1;i<=a;i++){
    	cin>>b[i]>>c[i];
	}
	if(a==1){
		cout<<"0";
		return 0;
	}
	if(a==2){
		if(b[1]==b[2]){
			if(c[1]==c[2]){
				cout<<"0";
		        return 0;
			}else{
				cout<<b[1];
				return 0;
			}
		}else if(b[1]!=b[2]){
			if(c[1]==c[2]){
				cout<<"0";
		        return 0;
			}else{
				cout<<min(b[1],b[2]);
				return 0;
			}
		}
	}
	int d=1;
	for(int i=2;i<=a;i++){
    	if(c[i]==c[i-1]){
    		++d;
		}
	}
	if(d==a){
		cout<<"0";
		return 0;
	}
	return 0;
}
