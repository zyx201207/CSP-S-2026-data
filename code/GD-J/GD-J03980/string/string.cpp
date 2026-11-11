#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string sum;
	for(int i=1;i<=n;i++){
		long long num;
		cin>>num;
		string s;
		cin>>s;
		for(int i=1;i<=num;i++){
			sum+=s;
		}
	}
	long long cnt=sum.size();
	long long ans=0;
	for(long long i=0;i<cnt;i++){
		if(sum[i]!=sum[cnt-1-i]){
			ans++;
		}
	}
	ans/=2;
	cout<<ans<<endl;
	return 0;
}
