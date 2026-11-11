#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
char c;
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>k;
		cin>>c;
		while(k--){
			s+=c;
		}
	}
 	long long L=0,R=s.size()-1;
	while(L<=R){
		if(s[L]==s[R]){
			L++,R--;
			continue;
		}
		ans++;
		L++,R--;
	}
	cout<<ans;
	return 0;
}
