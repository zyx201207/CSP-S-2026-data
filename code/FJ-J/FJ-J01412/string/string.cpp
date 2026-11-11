#include<bits/stdc++.h>
using namespace std;
unsigned long long ans,n,a[100005],l=1,r,now,maxx;
char b[100005];
bool aif;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;r=n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++){
		if(a[l]>a[r]){
			if(b[l]!=b[r])ans+=a[r];
			a[l]-=a[r];
			r--;
		}
		else if(a[r]>a[l]){
			if(b[l]!=b[r])ans+=a[l];
			a[r]-=a[l];
			l++;
		}
		else{
			if(b[l]!=b[r])ans+=a[r];
			l++,r--;
			//cout<<' '<<l<<' '<<r<<' '<<ans<<endl;
		}
		if(aif)break;
		if(l==r||l-r==1||r-l==1)aif=1;
	}
	cout<<ans;
	return 0;
}
