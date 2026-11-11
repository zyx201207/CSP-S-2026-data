//观山湖中学 刘郅铖 GZ-J00274
#include<bits/stdc++.h>
using namespace std;
	long long cnt;
	long long n,ans,length;
	char a;
	string res;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>cnt>>a;
		length+=cnt;
		for(long long j=0;j<cnt;j++)res+=a;
	}
	for(long long i=0;i<res.size()/2;i++){
		if(res[i]!=res[length-1-i])ans++;
	}
	cout<<ans;
}
