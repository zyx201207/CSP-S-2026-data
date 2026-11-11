#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans[5];
string s1,s2,s3,s4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>s1>>s2>>s3>>s4; 
	ans[1]=(s1==s3);
	ans[2]=(s2[0]==s4[0]&&s2[1]==s4[1]);
	int a=s2[2]-'A',b=s4[2]-'A';
	ans[3]=!((a<3)^(b<3));
	ans[4]=(abs(a-b)<=1); 
	ans[0]=1;
	for(int i=1;i<=4;i++)cout<<(ans[i]&=ans[i-1]);
	return 0; 
}
