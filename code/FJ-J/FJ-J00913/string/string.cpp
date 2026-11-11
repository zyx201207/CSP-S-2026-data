#include<bits/stdc++.h>
#define ul unsigned long long
using namespace std;
int n,l=1,r;
ul a[200020],s,ans;
char c[200020];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	l=1;
	r=n;
	while(l<r){
		if(a[l]>a[r]){
			if(c[l]!=c[r])ans+=a[r];
			a[l]-=a[r];
			r--;
		}else if(a[l]<a[r]){
			if(c[r]!=c[l])ans+=a[l];
			a[r]-=a[l];
			l++;
		}else{
			if(c[r]!=c[l])ans+=a[l];
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
} 
