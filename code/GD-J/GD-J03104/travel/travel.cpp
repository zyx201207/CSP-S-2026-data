#include<bits/stdc++.h>
#define ll long long
using namespace std;
//const int N=1e8+5; 
string c_1,s_1,c_2,s_2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1!=c_2)cout<<"0000";
	else{
		cout<<1;
		if(s_1[1]!=s_2[1])cout<<"000";
		else {
			cout<<1;
			if(('D'<=s_1[2]&&s_1[2]<='F')^('D'<=s_2[2]&&s_2[2]<='F'))cout<<"00";
			else {
				cout<<1;
				cout<<((int)abs(s_1[2]-s_2[2])==1);
			}
		}
	}
	
	
	
 return 0;
} 
