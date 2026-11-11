#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,m;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long i=1,j=n,l=a[1],r=a[n];
	while(i<j){
		if(l>r){
			if(c[i]!=c[j])ans+=r;
			l-=r,j--,r=a[j];
		}
		else if(l<r){
			if(c[i]!=c[j])ans+=l;
			r-=l,i++,l=a[i];
		}
		else{
			if(c[i]!=c[j])ans+=l;
			i++,j--,l=a[i],r=a[j];
		}
	}
	cout<<ans;
	return 0;
}
