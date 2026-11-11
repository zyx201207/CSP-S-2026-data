#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010],b[200010],hel[200010],her[200010];
char c[200010],cb[200010];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i],b[n-i+1]=a[i],cb[n-i+1]=c[i];
    for(int i=1;i<=n;i++)hel[i]=hel[i-1]+a[i],her[i]=her[i-1]+b[i];
    long long ans=0,last=0;
    int j=1;
    for(int i=1;i<=n;i++){
		if(hel[i]<=her[j]){
			if(c[i]!=cb[j])ans+=hel[i]-last;
			last=hel[i];
			continue;
		}
		if(cb[j]!=c[i]){
			ans+=her[j]-last;
		}
		last=her[j];
		while(her[j]<=hel[i]&&j!=n){
			if(c[i]!=cb[j]){
				ans+=her[j]-last;
			}
			last=her[j];
			j++;
		}
		if(c[i]!=cb[j]){
			ans+=hel[i]-last;	
		}
		last=hel[i];
	}
	cout<<ans/2;
    return 0;
}
