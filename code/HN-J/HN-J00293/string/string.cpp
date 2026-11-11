#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,a[N],s[N],cnt,ans,l,r;
char sr[N],ch[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>sr[i];
	for(int i=1;i<=n;i++){
		int j=i,sum=a[i];
		while(j<n&&sr[j+1]==sr[i])sum+=a[++j];
		s[++cnt]=sum;
		ch[cnt]=sr[i];
		i=j;
	}
	n=cnt;
	l=1,r=n;
	while(l<r){
		if(s[l]<s[r]){
			if(ch[l]!=ch[r])ans+=s[l];
			s[r]-=s[l];
			l++; 
		}else if(s[l]>s[r]){
			if(ch[l]!=ch[r])ans+=s[r];
			s[l]-=s[r];
			r--;
		}else{
			if(ch[l]!=ch[r])ans+=s[l];
			l++,r--;
		}
	}
	cout<<ans;
	return 0;
}

