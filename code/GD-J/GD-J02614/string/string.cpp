#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010],l,p,ans;
char s[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int i=1,p=n;
	while(i<p){
		if(a[i]>=a[p]){
			if(s[i]!=s[p]){
			ans+=a[p];
		}
			a[i]-=a[p];
			while(a[i]!=0&&i<p){
				p--;
				if(a[i]>=a[p]){
					if(s[i]!=s[p])
					ans+=a[p];
					a[p]=0;
					a[i]-=a[p];
				}else{
					if(s[i]!=a[p])
					ans+=a[i];
					a[p]-=a[i];
					break;
				}
			}
		i++;
		}else{
			if(s[i]!=s[p]){
			ans+=a[i];
		}
			a[p]-=a[i];
			while(a[p]!=0&&i<p){
				i++;
				if(a[p]>=a[i]){
					if(s[i]!=s[p])
					ans+=a[i];
					a[i]=0;
					a[p]-=a[i];
				}else{
					if(s[i]!=a[p])
					ans+=a[p];
					a[i]-=a[p];
					break;
				}
			}p--;
		}
	}cout<<ans;
	return 0;
}
