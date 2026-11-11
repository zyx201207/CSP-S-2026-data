#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0;
	cin>>n;
	string s;
	while(n--){
		int x;
		char y;
		cin>>x>>y;
		while(x--) s+=y;
	}
	long long ans=s.size();
	if(ans%2==0){
		for(int i=0;i<ans/2;i++) if(s[i]!=s[ans-i-1]) cnt+=1;
		cout<<cnt;
		return 0;
	}
	else{
		for(int i=0;i<ans/2,i!=ans/2+1;i++) if(s[i]!=s[ans-i-1]) cnt+=1;
		cout<<cnt;
		return 0;
	}
	return 0;
}
