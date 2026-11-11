#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a,sum,h,ans;
string s;
char c;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
		sum+=a;
	}
	if(sum%2==0)h=sum/2;
	else h=(sum-1)/2;
	sum--,h--;
	for(int i=0;i<=h;i++){
		if(s[i]!=s[sum-i]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
