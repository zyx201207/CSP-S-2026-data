#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
bool a=true,b=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1"; 
		for(int i=0;i<=1;i++){
			if(s1[i]!=s2[i]){
				a=false;
			}
		}
		if(a){
			cout<<1;
			if((int(s1[2])<=int('C') && s2[2]>=int('D')) || (int(s2[2])<=int('C') && s1[2]>=int('D'))){
				b=false;
				cout<<0;
			}
			else{
				cout<<1;
			}
			if((s1[2]-s2[2]==1 || s2[2]-s1[2]==1) && b){
				cout<<1;
			}else{
				cout<<0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
		
			
	return 0;
}
//	02 01A 02 01B
//  02 01C 02 01A
//  02 01C 02 01D
