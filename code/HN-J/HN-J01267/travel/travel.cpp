#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
bool tc(int a,int b){
	if(a=='F' || a=='D'){
		if(b=='F' || b=='D'){
			return true;
		}
	}
	if(a=='A' || a=='B' || a=='C'){
		if(b=='A' || b=='B' || b=='C'){
			return true;
		}
	}
	return false;
}
void xl(int a,int b){
	int maxn=max(a,b);
	if(maxn-a==1||maxn-b==1){
		cout<<'1';
	}else{
		cout<<'0';
	}
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		cout<<'1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<'1';
			if(tc(s1[2],s2[2])){
				cout<<'1';
				xl(s1[2],s2[2]);
			}else{
				cout<<"00";
				return 0;
			}		
		}else{
			cout<<"000";
			return 0;
		}
	}
}

