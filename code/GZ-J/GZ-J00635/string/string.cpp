//GZ-J00635 兴义市弘毅中学 廖鑫豪 
#include<bits/stdc++.h>
using namespace std;
long long n,sum,a[200200],ans;
char c[200200];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(long long j=1;j<=a[i];j++){
			s[sum+j]=c[i];
		}
		sum+=a[i];
	}
	if(sum%2){
		long long b=(sum+1)/2;
		for(long long i=1;i<=(sum-1)/2;i++){
			if(s[b+i]!=s[b-i]){
				ans++;
			}
		}
	}
	else{
		long long b=sum/2;
		for(long long i=1;i<=sum/2;i++){
			if(s[b+i]!=s[b-i+1]){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
} 
