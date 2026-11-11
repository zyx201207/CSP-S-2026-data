#include<bits/stdc++.h>
using namespace std;
char t[1000000000];
long long ans;
long long cnt;
bool hw(){
	for(long long i=1;i<=ans;i++){
		if(t[i] != t[ans+1-i]) return 0;
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0); 
	long long n;
	cin>>n;
	long long num = 1;
	for(long long i=1;i<=n;i++){
		long long a = 0;
		char c;
		cin>>a>>c;
		ans+=a;
		for(long long j=1;j<=a;j++){
			t[num] = c;
			num++;
		}
	}
	if(hw() == 1){
		cout<<'0';
		return 0;
	}
	for(long long i=1;i<=ans/2+1;i++){
		if(t[i] != t[ans+1-i]){
			cnt++;
			}
	}
	cout<<cnt;
	return 0;
}
