#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int a,n,sum=0,cnt=0;cin>>n;
	string s1,s2;char c;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=sum;j<=sum+a-1;j++){
			s1[j]=c;
		}
		sum+=a;
	}int j=0;
	for(int i=sum-1;i>=0;i--){
		s2[j]=s1[i];
		j++;
	}
	for(int i=0;i<=(sum-1)*0.5;i++){
		if(s1[i]!=s2[i]) cnt++;
	}
	cout<<cnt;
	return 0;
}

