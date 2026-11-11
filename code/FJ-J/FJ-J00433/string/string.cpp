#include<bits/stdc++.h>
using namespace std;
int z,cs=0;
string hw="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>z;
	if(z==2){
		int gs1,gs2;
		char zf1,zf2;
		cin>>gs1>>zf1>>gs2>>zf2;
		if(zf1==zf2){
			cout<<0;
			return 0;
		}else{
			cout<<min(gs1,gs2);
			return 0;
		}
	}
	for(int i=1;i<=z;i++){
		int gs;
		char zf;
		cin>>gs>>zf;
		for(int i=1;i<=gs;i++){
			hw+=zf;
		}
	}
	if(hw.size()%2==0){
		for(int i=0;i<hw.size()/2;i++){
			if(hw[i]!=hw[hw.size()-i-1]){
				cs++;
			}
		}
	}else{
		for(int i=0;i<hw.size()/2;i++){
			if(hw[i]!=hw[hw.size()-i-1]){
				cs++;
			}
		}
	}
	cout<<cs;
return 0;
}
