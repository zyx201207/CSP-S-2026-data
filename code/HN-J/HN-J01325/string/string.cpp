#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
long long n,ans,sum;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;char c;cin>>x>>c;
		for(int j=1;j<=x;j++)s+=c;
		sum+=x;
	}
	for(int i=0,j=sum-1;i<(sum+1)/2;i++,j--){
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}

