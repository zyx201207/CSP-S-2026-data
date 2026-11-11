#include<bits/stdc++.h>
using namespace std;
string s;
long long n,x,ans;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		for(int j=1;j<=x;j++)s+=c;
	}
	long long l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r])ans++;
		l++;
		r--;	
	}
	cout<<ans;
}
