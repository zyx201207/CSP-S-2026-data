#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int l[200005],r[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int num=0;
	for(int i=1;i<=n;++i){
		int p;
		cin>>p>>c[i];
		num+=p;
		l[i]=r[i-1]+1;
		r[i]=l[i]+p-1;
	}
	int l1=1,l2=1,r1=num,r2=n;
	int ans=0;
	while(l2<r2&&l1<r1){
		if(r[l2]-l1+1<r1-l[r2]+1){
			if(c[l2]!=c[r2])ans+=r[l2]-l1+1;
			r1-=(r[l2]-l1+1);
			l2++;
			l1=l[l2];
		}
		else if(r[l2]-l1+1>r1-l[r2]+1){
			if(c[l2]!=c[r2])ans+=r1-l[r2]+1;
			l1+=r1-l[r2]+1;
			r2--;
			r1=r[r2];
		}
		else{
			int p=r[l2]-l1+1;
			if(c[l2]!=c[r2])ans+=p;
			l2++,r2--;
			l1=l[l2],r1=r[r2];
		}
	}
	cout<<ans;
	return 0;
}
