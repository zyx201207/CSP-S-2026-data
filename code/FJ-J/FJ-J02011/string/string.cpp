#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long n,a[200010],c[200010];
	cin>>n;
	for(long long i=1;i<=n;i++){
		char ch; 
		cin>>a[i]>>ch;
		c[i]=ch-'a';
	}
	long long i=1,j=n,ans=0,l=0,r=0;
	while(i<j){
		if(a[i]-l>a[j]-r){
			l+=a[j];
			if(c[i]!=c[j])ans+=a[j]-r;
			j--;
			r=0;
	    }
		else if(a[i]-l==a[i]-r){
			if(c[i]!=c[j])ans+=a[i]-l;
			j--;
			i++;
			r=0;
			l=0;
		}
		else{
			r+=a[i];
			if(c[i]!=c[j])ans+=a[i]-l;
			i++;
			l=0;
		}
	}
	cout<<ans;
	return 0;
} 
