#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mn=2e5;
const int maxn=mn+10;
int n,a[maxn],ans=0;char b[maxn];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	int i=1,j=n;
	while(i<=j){
		if(a[i]>=a[j]){
			int flag=a[j];
			a[i]-=a[j];a[j]=0;
			if(b[i]!=b[j])ans+=flag;
		}else{
			int flag=a[i];
			a[j]-=a[i];a[i]=0;
			if(b[i]!=b[j])ans+=flag;
		}if(a[i]<=0)i++;
		if(a[j]<=0)j--;
	}cout<<ans;
	return 0;
}
