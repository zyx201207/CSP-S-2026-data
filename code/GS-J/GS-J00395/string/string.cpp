#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt=0,num=0;
string str="",str2="";
int main(){
	freopen("string6.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		num+=a;
		for(ll j=1;j<=a;j++){
			str+=c;
		}
	}
	for(ll i=0;i<num;i++){	
		if(str[i]==str[num-i-1]){
			continue;
		}else{
			str[num-i-1]=str[i];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
