#include<bits/stdc++.h>
using namespace std;
long long n,x[200005],b[200005],t,ans=0;
string a;
char y[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	t=n;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
	for(int i=1;i<=t;i++){
	    if(!b[i]){
			if(x[i]>x[t]){
				x[i]-=x[t];
				if(y[i]!=y[t])ans+=x[t];
				t--,i--;
			}
			if(x[i]==x[t]&&y[i]!=y[t])ans+=x[t],t--;
			if(x[i]<x[t]){
				while(x[i]<x[t]){
				   x[t]-=x[i];
				   if(y[i]!=y[t])ans+=x[i];
				   i++;
			    }
			    t--;
			}
		}
	}
	cout<<ans;
	return 0;
}
