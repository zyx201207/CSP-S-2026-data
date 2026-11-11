#include<bits/stdc++.h>
using namespace std;
int n;
long long ans,a[200005];
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>s[i];
	}
	int l=n;
	for(int i=1;i<=n;i++){
		if(i==l) break;
		while(a[i]>0){
			if(s[i]==s[l]){
				if(a[i]>=a[l]) a[i]-=a[l],l--;
				else a[l]-=a[i],a[i]=0;
			}
			else{
				ans+=min(a[i],a[l]);
				if(a[i]>=a[l]) a[i]-=a[l],l--;
				else a[l]-=a[i],a[i]=0;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
