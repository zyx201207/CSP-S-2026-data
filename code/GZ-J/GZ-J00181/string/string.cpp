//GZ-J00181 贵阳市第一中学 张梁予 
#include<bits/stdc++.h>
using namespace std;
string s,s1;
long long sum,ans,n,a[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s1;
		for(int j=1;j<=a[i];j++) s+=s1;
		sum+=a[i];
	}
	for(int i=1;i<=sum/2;i++){
		if(s[i-1]!=s[sum-i]) ans++;
	}
	cout<<ans;
	return 0;
}
