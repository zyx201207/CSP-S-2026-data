#include<bits/stdc++.h>
#define ll long long //Trick||Treat!
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(!((s1[2]>='D')^(s2[2]>='D'))){
				cout<<1;
				if(abs(s1[2]-s2[2])==1){
					cout<<1;
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
/*
题目大意：有17个车厢，其中1和16是一等，其余二等，他们都坐在二等车厢 

然后就不说了 
*/
