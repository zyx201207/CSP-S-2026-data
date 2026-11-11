#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	LL n;
	cin>>n;
	string s="";
	while(n--){
		LL a;
		cin>>a;
		char c;
		cin>>c;
		if(a>=1000000000){
			cout<<"0";
			return 0;
		}
		for(LL i=0;i<a;i++){
			s+=c;
		}
	}
	LL i=0,j=s.size()-1;
	LL ans=0;
	while(i<j){
		if(s[i]!=s[j]){
			ans++;
		}
		i++,j--;
	}
	cout<<ans;
	return 0;
}

