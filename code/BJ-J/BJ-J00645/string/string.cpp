#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,L=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		string st;
		cin>>a>>st;
		for(long long j=1;j<=a;j++){
			s+=st;
			L++;
		}
	}
	int ans=0;
	for(int i=0;i<=L/2-1;i++){
		if(s[i]!=s[L-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
