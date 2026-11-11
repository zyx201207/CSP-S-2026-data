#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	//1
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	//2
	bool flag = false;
	int len = s1.size();
	for(int i = 0;i < len-1;i++){
		if(s1[i]!=s2[i]){
			flag = true;
		}
	}
	if(flag){
		cout<<"000";
		return 0;
	}
	else cout<<1;
	//3
	if(s1[len-1]<='C'&&s1[len-1]>='A'&&s2[len-1]<='C'&&s2[len-1]>='A') cout<<1;
	else if(s1[len-1]<='F'&&s1[len-1]>='D'&&s2[len-1]<='F'&&s2[len-1]>='D') cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	//4
	int ans = abs((s1[len-1]-'A')-(s2[len-1]-'A'));
	if(ans>1) cout<<0;
	else cout<<1;
	return 0;
}
