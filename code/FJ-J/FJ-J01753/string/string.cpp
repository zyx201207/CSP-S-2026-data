#include<bits/stdc++.h>
using namespace std;
int n,a,qz[200005];
long long len,ans;
string s,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
cin>>n;
for(int i=1;i<=n;i++){
cin>>a>>c;
while(a--)s+=c;
}
len=s.size();
if(len%2==1){
//	int mid=(len+1)/2+1;
//	int now=lower_bonud(qz+1,qz+n+1,mid)-qz;
//	if(a[now]-mid==0)ans=qz[n]-qz[now];
//	else ans=
for(int i=(len+1)/2+1;i<len;i++){
		int j=len-i;
		if(s[i]!=s[j])ans++;
	}
}else {
	for(int i=len/2+1;i<len;i++){
		int j=len-i;
		if(s[i]!=s[j])ans++;
	}
}
cout<<ans;
	return 0;
}
