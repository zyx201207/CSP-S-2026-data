#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long ans = 0;
	while(n--){
		long long x;
		char c;
		cin>>x>>c;

 		ans+=x;
		for(int i = 1;i<=x;i++){
			s+=c;
		}
	}
	long long sum=0;
	long long x = ans;
	if(ans%2 == 0) ans-=1;
	for(int i = 0;i<=ans/2;i++){
		if(x%2 == 0){
			if(s[i]!=s[ans-i]) sum++;
		}
		else{
			if(s[i]!=s[ans-1-i]) sum++; 
		}
		
	}
	cout<<sum;
	
	
	return 0;
}
