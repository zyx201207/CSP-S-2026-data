#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
string pc;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		long long a;
		char b;
		cin>>a>>b;
		for(int j=0;j<a;j++){
			pc+=b;
		}
	}
	long long sum=pc.size();
	if(sum%2==0)sum/=2;
	else sum=sum/2+1;
	for(int i=0;i<sum;i++){
		if(pc[i]!=pc[pc.size()-1-i])ans++;
	}
	cout<<ans;
}
