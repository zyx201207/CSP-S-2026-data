#include<bits/stdc++.h>
using namespace std;
long long m,n,a[200005],t,cnt[200005],ans;bool c[200005][40],d[200005];
int main(){
	//freopen("and.in","r",stdin); 
	//freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int q1=a[i],t=0;
		while(q1!=0){
			if(q1%2==1){
				c[i][t]=1;cnt[t]++;
			}
			t++;
			q1/=2;
		}
	}int now=0;
	for(int i=32;i>=0;i--){
		if(cnt[i]>=m){
			now=i;
			break;
		}
	}ans+=(1<<now);
	for(int i=1;i<=n;i++){
		if(c[i][now]==1){
			d[i]=1;
		}
	}
	for(int i=now-1;i>=0;i--){
		if(cnt[i]<m){
			continue;
		}int s=0;
		for(int j=1;j<=n;j++){
		    if(d[j]==1&&c[j][i]==1)s++;
		}
		if(s>=m){
			ans+=(1<<i);
			for(int j=1;j<=n;j++){
				if(d[j]==1&&c[j][i]==0)d[j]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
