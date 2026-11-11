#include<bits/stdc++.h>
using namespace std;
int a[200005],lx,rx,n;
long long ans;
char x[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>x[i];
	}
	lx=1,rx=n;
	while(lx<rx){
		if(a[lx]>a[rx]){
			if(x[lx]!=x[rx])ans+=a[rx];
			a[lx]-=a[rx];
			rx--;
		}else if(a[lx]<a[rx]){
			if(x[lx]!=x[rx])ans+=a[lx];
			a[rx]-=a[lx];
			lx++;
		}else{
			if(x[lx]!=x[rx])ans+=a[rx];
			lx++;
			rx--;
		}
	}
	cout<<ans;
}
