#include <bits/stdc++.h>
using namespace std;
const int N=200005;
long long a[N];
char ch[N];
vector<char> s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s.push_back(ch[i]);
		}
	}
	int len=s.size();
	for(int i=0,j=len-1;i<=j;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
}