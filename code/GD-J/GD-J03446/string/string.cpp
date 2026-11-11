#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0,ans=0;
	string s={};
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		string d;
		cin>>d;
		for(long long j=1;j<=a;j++){
			s+=d;
			cnt++;
		}
	}
	long long mid=s.size()/2;
	for(long long i=0,j=cnt-1;i<mid;i++,j--){
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
}
