#include<bits/stdc++.h>
#define int long long
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
int ans,n,sum,a[200005];
char c[200005];
signed main(){
	fre("string");
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(sum>1000000){
		for(int i=2;i<=n;i++)a[i]+=a[i-1];
		for(int i=1;i<=n;i++){
			int a1=a[i-1],a3=a[n]-a1;
			if(a1*2>a[n])break;
			int x=lower_bound(a+1,a+n+1,a3)-a-1;
			while(a1>0&&x>0){
				int a2=min(a1,min(a[x+1]-a[x],a3-a[x]+1));
				if(c[i]!=c[x])ans+=a2;
				x--;
				a1-=a2;
			}
		}
		cout<<ans;
	}
	else{
		string s="";
		for(int i=1;i<=n;i++)while(a[i]--){
			s+=c[i];
		}
		int n1=s.size();
		for(int i=0;i*2<n1;i++){
			if(s[i]!=s[n1-i-1])ans++;
		}
		cout<<ans;
	}
	return 0;
}


