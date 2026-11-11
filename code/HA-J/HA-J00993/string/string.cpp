#include<bits/stdc++.h>
using namespace std; 

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	long long cnt=0,ans=0;
	long long n,x=0;
	cin>>n;
	string s;
	char d;
	for(int i=1;i<=n;i++){
		cin>>x>>d;
		for(int j=cnt;j<cnt+x;j++){
			s[j]=d;
		}
		cnt+=x;
	}
	for(long long i=0,j=cnt-1;i<=cnt/2-1,j>=cnt-cnt/2;i++,j--){
		if(s[i] != s[j]){
			ans++;
			s[j]=s[i];
		}
	}
	cout<<ans;
	return 0;
}
