#include <bits/stdc++.h>
using namespace std;
#define int long long
string c1,c2,c3,c4;
int arr[105][105]={{2,2,1,0,0},{2,2,2,0,0},{1,2,2,0,0},{0,0,0,2,2},{0,0,0,2,2}};
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(c2[0]==c4[0] && c2[1]==c4[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(arr[c2[2]-'A'][c4[2]-'A']){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(arr[c2[2]-'A'][c4[2]-'A']==2){
		cout<<1;
	}
	else{
		cout<<"0";
	}
	return 0;
}
