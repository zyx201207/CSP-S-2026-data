#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,sum,pos;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll a;
		string c;
		cin>>a>>c;
		pos+=a;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	pos-=1;
	for(int i=pos;i>=0;i--){
		if(i>=pos/2+1){
			if(s[i]!=s[pos-i]){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
