#include<bits/stdc++.h>
using namespace std;
char c[200005],d[200005];
long long a[200005],b[200005],ans,sum,now1,now2,p1,p2;
int n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	p2=n,p1=1;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i],sum+=a[i];
	for(int i=1;now1<=sum/2;i++) now1+=a[i],p1=i;
	a[p1]-=sum%2,now1-=sum%2;
	if(sum/2+a[p1]-now1>=now1-sum/2) a[p1]=sum/2+a[p1]-now1-(now1-sum/2);
	else a[p1]=now1-sum/2-(sum/2+a[p1]-now1),p1--;
	now1=0,now2=a[n],p2=n;
	for(int i=1;i<=p1;i++){
		now1+=a[i];
		if(now1<=now2){
			if(c[i]!=c[p2]) ans+=a[i];
		}
		else{
			if(c[i]!=c[p2]) ans+=now2-(now1-a[i]);
			while(now1>now2){
				p2--;
				now2+=a[p2];
				if(c[i]!=c[p2]){
					if(now1>now2) ans+=a[p2];
					else ans+=now1-now2+a[p2];
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
