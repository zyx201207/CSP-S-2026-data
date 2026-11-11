#include<bits/stdc++.h>
using namespace std;
long long cnt=0,ans=0,c,n,s[200001],ss[200001]; 
char t[200001],tt[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
		tt[n-i+1]=t[i];
		ss[n-i+1]=s[i];
		ans+=s[i];
	}
	for(int i=1;i<=(1+n)/2;i++){
		if(t[i]!=tt[i]){
			cnt+=max(s[i],ss[i]);
		}
	}
	cout<<min(ans-cnt,cnt);
}
