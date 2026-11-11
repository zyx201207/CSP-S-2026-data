#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005];
char b[2000005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int s=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		s+=a[i];
	}
	int ans=0;
	int l=1;
	int r=n;
	int pl=a[1];
	int pr=a[n];
	//shuangzhizhen?
	while(l<r){
		if(pl==pr){
			if(b[l]!=b[r])ans+=pl;
			r--;
			l++;
			pl=a[l];
			pr=a[r];
		}else if(pl>pr){
			if(b[l]!=b[r])ans+=pr;
			r--;
			pl-=pr;
			pr=a[r];
		}else{
			if(b[l]!=b[r])ans+=pl;
			l++;
			pr-=pl;
			pl=a[l];
		}	
	}
	cout<<ans;
	return 0;
}
