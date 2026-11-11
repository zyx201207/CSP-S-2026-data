#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,sum;
char c1[2000005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++){
			sum++;
			c1[sum]=c;
		}
	}
	long long ji=(sum+1)/2;
	for(int i=1;i<=ji;i++){
		if(c1[i]!=c1[sum-i+1]){
//			cout<<ans<<"\n";
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
