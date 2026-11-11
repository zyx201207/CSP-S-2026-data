//GZ-J00145 贾景栎  遵义市第四中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,l[1001],r[1001],s1[10010];
	long long len=0,ans=0,cnt[10010],n,a[10010];
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>s1[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=s1[i];
		}
	}
	len=s.size();
	for(long long i=1;i<=len/2+1;i++)l[i]=s[i];
	for(long long i=len/2+1;i<=len;i++)r[i]=s[i];
	for(long long i=1,j=len;i<=len/2+1,j>=len/2+1;i++,j--){
		if(l[i]==r[j])cnt[i]=1;
		else cnt[i]=0;
	}
	for(long long i=1;i<=len/2;i++){
		if(cnt[i]==0)ans++;
	}
	int cmp=0;
	for(long long i=1;i<=n;i++){
		if(s1[i]==s1[i+1])cmp=1;
	}
	if(cmp==1)cout<<0;
	else cout<<ans;
	return 0;
}
