#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string c_1,s_1,c_2,s_2;
bool check(string x,string y){
	if(x[0]==y[0] && x[1]==y[1]) return 1;
	return 0;
}
bool f(int x,int y){
	int sum=abs(x-y);
	if(sum==1) return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(!check(c_1,c_2)){
		cout<<0000;
	}else{
		cout<<1;
		if(!check(s_1,s_2)){
			cout<<000;
		}else{
			cout<<1;
			if(s_1[2]<='C' && s_2[2]<='C'){
				cout<<1;
				if(f(s_1[2]-'0',s_2[2]-'0')) cout<<1;
				else cout<<0;
				
			}else if((s_1[2]>='D' && s_2[2]>='D')){
				cout<<11;
			}else{
				cout<<00;
			}
		}
	}
	return 0;
}
