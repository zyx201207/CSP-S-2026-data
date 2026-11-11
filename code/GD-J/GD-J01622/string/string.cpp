#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt=1,ans,sum;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s[0]=1;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		sum+=a;
		for(int i=cnt;i<cnt+a;i++){
			s[i]=c;
		}
		cnt+=a;
	}
	for(int i=1;i<=sum/2;i++){
		if(s[i]!=s[sum+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
