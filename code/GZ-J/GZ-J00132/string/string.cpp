//蒋木铮 GZ-J00132 贵阳第一中学 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
string s;
char c[N];
int a[N];
long long l;
int main(){
	int n;
	cin>>n;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//O(N*a[i]max)
	for(int i=1;i<=n;i++){
		int s1;
		char t;
		cin>>s1>>t;
		l+=s1;
		for(int j=1;j<=s1;j++) s+=t;
	}
	int ans=0;
	//cout<<l<<" ";
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[l-1-i]) s[i]=s[l-1-i],ans++;
	}
	cout<<ans;

	return 0;
}
