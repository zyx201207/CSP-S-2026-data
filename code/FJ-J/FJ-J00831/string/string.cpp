#include<bits/stdc++.h>
using namespace std;
#define int long long
int q[200005];
int t[30];
int a[200005];
char c[200005];
int n,ans,mid,sum;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		q[i+1]=q[i]+a[i];
	}
	for(int i=1;i<=n;i++){
		if((sum/2)>=q[i]&&(sum/2)<q[i+1]){
			if(sum%2!=0){
				a[i]--;
			}
			mid=i-1;
		}
	}
	for(int i=1;i<=mid;i++){
		int s=c[i]-'a'+1;
		t[s]+=a[i];
	}	
	for(int i=mid+1;i<=n;i++){
		int s=c[i]-'a'+1;
		if(t[s]>=1){
			t[s]-=min(t[s],a[i]);
		}
	}
	for(int i=1;i<=26;i++){
		ans+=t[i];
	}
	cout<<ans;
	return 0;
} 
