#include<bits/stdc++.h>
#define int long long
using namespace std;
string a1,a2,b1,b2;
bool t1,t2,t3,t4;
bool r(char a){
	return a<='C';
}
bool l(char a){
	return a>'C';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
    	t1=1;
    	if(a2[0]==b2[0]&&a2[1]==b2[1]){
    		t2=1;
    		if((r(a2[2])&&r(b2[2]))||(l(a2[2])&&l(b2[2]))){
    			t3=1;
    			if(fabs(a2[2]-b2[2])==1){
    				t4=1;
				}
			}
		}
	}
	cout<<t1<<t2<<t3<<t4;
	return 0;
}
