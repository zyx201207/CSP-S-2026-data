#include<bits/stdc++.h>
using namespace std;
int n,l,r;
long long ans=0,a[200500];
char s[200500];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	l=1,r=n;
	while(l<r){
		int num=min(a[l],a[r]);
		if(s[l]!=s[r])ans+=num;
		a[l]-=num;
		a[r]-=num;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<ans;
	return 0;
} 
