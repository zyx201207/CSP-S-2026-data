#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,sum,ans,cnt1,cnt2,a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i],sum+=a[i];
	cnt1=1,cnt2=sum,sum/=2;
	int i=1,j=n;
	while(cnt1<=sum){
		if(c[i]!=c[j]){
			ans+=min(a[i],a[j]); 
			if(a[i]>a[j]) cnt1+=a[j],cnt2-=a[j,a[i]-=a[j],a[j]=0],j--;
			else if(a[i]<a[j]) cnt1+=a[i],cnt2-=a[i],a[j]-=a[i],a[i]=0,i++;
			else cnt1+=a[i],cnt2-=a[i],a[i]=0,a[j]=0,i++,j--;
		}else{
			if(a[i]>a[j]) cnt1+=a[j],cnt2-=a[j,a[i]-=a[j],a[j]=0],j--;
			else if(a[i]<a[j]) cnt1+=a[i],cnt2-=a[i],a[j]-=a[i],a[i]=0,i++;
			else cnt1+=a[i],cnt2-=a[i],a[i]=0,a[j]=0,i++,j--;
		}
	}
	cout<<ans;
	return 0;
}

