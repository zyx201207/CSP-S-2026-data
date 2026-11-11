#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ans=0;
	string a1,b1,a2,b2;
	if(a1 != a2){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
		int sum=0,flag=0; 
		for(int i=0;i<3;i++){
			if(b1[i]==b2[i]){
				sum++;
			}
			if(ans=abs(b1[2]-b2[2])==1){
				if(b1[2]=='C' && b2[2]=='D' || b1[2]=='D' && b2[2]=='C'){
					flag=0;
				}else{
					flag=1;
				}
			}
			if(ans=abs(b1[2]-b2[2])==2 && b1[2]=='A' && b2[2]=='C' || b1[2]=='C' && b2[2]=='A') {
				flag=1;
			}
		}
		if(sum==2){
			cout<<"1";
		}else{
			cout<<"000";
			return 0; 
		}
		if(sum==2 && flag==1){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
		if(abs(b1[2]-b2[2])==1){
			cout<<"1";
		}else{
			cout<<"0";
			return 0;
		}
	}
	return 0;
}
