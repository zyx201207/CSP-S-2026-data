#include<bits/stdc++.h>
using namespace std;
long long num[200005],ans;char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	long long sum=0;string s="";
	for(long long i=1;i<=n;i++){
		cin>>num[i]>>c[i];
		for(int j=1;j<=num[i];j++){
			s.push_back(c[i]);
		}
		sum+=num[i];
	}
	int l=sum/2+1;if(sum%2==1)l++;
	for(int i=l;i<=sum;i++){
		if(s[i]!=s[sum-i+1])ans++;
	}
	cout<<ans;
	return 0;
}
