#include<bits/stdc++.h>
using namespace std;
string s;
map<char,long long>mp;
long long n,ans,cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		int x_1;
		char c_1;
		cin>>x_1>>c_1;
		cout<<0;
		return 0;
	}
	
	if(n==2){
		int x_1,x_2;
		char c_1,c_2;
		cin>>x_1>>c_1>>x_2>>c_2;
		if(c_1==c_2){
			cout<<0;
			return 0;
		}
		if((x_1==1&&x_2%2==0)||(x_2==1&&x_1%2==0)){
			cout<<1;
			return 0;
		}
		if(x_1==x_2&&x_1%2==0){
			cout<<x_1/2;
			return 0;
		}
		if(x_1%2!=0&&x_2%2==0){
			cout<<x_2/2;
		}
		if(x_2%2!=0&&x_1%2==0){
			cout<<x_1/2;
		}
	}
	
	for(int i=1;i<=n;i++){
		long long x;
		char c;
		cin>>x>>c;
		if(mp[c]==0)
			cnt++;
		mp[c]+=x;
	}
	for(int i='a';i<='z';i++){
		if(mp[i]%2==0){
			ans+=mp[i]/2;
		}
	}
	cout<<ans;
	return 0;
}
