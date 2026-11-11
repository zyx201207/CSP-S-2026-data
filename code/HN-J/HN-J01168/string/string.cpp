#include<bits/stdc++.h>
using namespace std;

long long n,a[200050];
char c[200050];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	long long x=1,y=1,ans=0;
	while(1){
		if(n-y+1<=x)break;
		if(a[x]==a[n-y+1]){
			if(c[x]!=c[n-y+1])ans+=a[x];
			x++,y++;
		}else if(a[x]>a[n-y+1]){
			while(a[x]){
				if(a[x]==0)break;
				if(c[x]==c[n-y+1]){
					y++;
					if(a[x]!=a[n-y+1]){
						if(a[x]>a[n-y+1])a[x]-=a[n-y+1],y++;
						else{
							a[n-y+1]-=a[x];
							a[x]=0;
							x++;
							break;
						}
					}
				}
				else{
					if(a[x]==a[n-y+1]){
						if(c[x]!=c[n-y+1])ans+=a[x],a[x]-=a[n-y+1];
						x++,y++;
						break;
					}else{
						if(a[x]>a[n-y+1])ans+=a[n-y+1],a[x]-=a[n-y+1],y++;
						else{
							ans+=a[x];
							a[n-y+1]-=a[x];
							a[x]=0;
							x++;
							break;
						}
					}
				}
			}
		}else{
			if(c[x]==c[n-y+1]){
				a[n-y+1]-=a[x];
				x++;
			}else{
				a[n-y+1]-=a[x];
				ans+=a[x];
				x++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
