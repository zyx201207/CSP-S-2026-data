#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cout.tie(0);
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	string s;
	int sum=0;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		for(int i=1;i<=x;i++) s+=y;
		sum+=x;
	}
	int cnt=0;
	for(int i=0;i<s.length();i++){
		if(s[i]!=s[sum-i])
			cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
