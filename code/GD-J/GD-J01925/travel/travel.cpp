#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll a,b;
string al,bl;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
   // scanf("%lld,%lld,%lld,%lld",a,al,b,bl);
   cin>>a>>al>>b>>bl;
    if(a!=b){
    cout<<"0000";
	}else if(al[0]!=bl[0] or al[1]!=bl[1]){
		cout<<"1000";
	}else if(al[2]=='A' or al[2]=='C' or al[2]=='B'){
		if(bl[2]=='D' or bl[2]=='F'){
			cout<<"1100";
		}else{
			if(abs(int(bl[2]) -int(al[2]))==1){
				cout<<"1111";
			}else{
				cout<<"1110";
			}
		}
	}else{
			if(bl[2]=='D' or bl[2]=='F02 02B 02 01A'){
			cout<<"1111";
		}else{
		  cout<<"1100";
		}
	}
    return 0;
}
