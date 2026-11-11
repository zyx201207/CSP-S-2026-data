#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
long long a,cnt,sum,ans;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s[cnt]=c;
			cnt++;
		}
	}
	sum=cnt;
	for(int p=0;p<=(cnt+1)/2-1;p++){
		if(s[p]!=s[sum]){
			ans++;
		}
		sum--;
	}
	cout<<ans;
	return 0;
}
