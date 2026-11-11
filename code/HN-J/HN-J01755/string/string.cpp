#include<bits/stdc++.h>
using namespace std;
int n;
long long a;
char ch;
long long sum;
vector<char> s;
long long mid,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>ch;
		sum+=a;
		for(int i=1;i<=a;i++){
			s.push_back(ch);
		}
	}
	mid=(sum+1)/2;
	for(int i=1;i<=mid;i++){
		if(s[i-1]!=s[sum-i]){
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
}
