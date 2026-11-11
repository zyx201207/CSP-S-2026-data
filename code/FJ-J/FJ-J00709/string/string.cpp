#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005],ans=0,i=1;
string s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n<=1)cin>>a[1]>>s[1],cout<<0;
	else if(n<=2){
		for(int j=1;j<=n;j++)cin>>a[j]>>s[j];
		if(s[1]==s[2])cout<<0;
		else cout<<min(a[1],a[2]);
	}
	else {
		for(int j=1;j<=n;j++)cin>>a[j]>>s[j];
		while(true){
			if(s[i]!=s[n]){
				if(a[i]>a[n])ans+=a[n],a[i]-=a[n],n--;
				else if(a[i]==a[n])ans+=a[i],i++,n--;
				else ans+=a[i],a[n]-=a[i],i++;
			}
			else i++,n--;
			if(i>=n)break;
		}
	cout<<ans;
	}
	return 0;
}
