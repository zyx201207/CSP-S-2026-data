#include<bits/stdc++.h>
#define ll long long
#define N 200001
using namespace std;
ll n,a[N],cnt1=1,cnt2,ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	cnt2=n;
	while(cnt1<cnt2){
		if(a[cnt1]<a[cnt2]){
			if(c[cnt2]!=c[cnt1]) ans+=a[cnt1];
			a[cnt2]-=a[cnt1];
			cnt1++;
		}else if(a[cnt1]>a[cnt2]){
			if(c[cnt2]!=c[cnt1]) ans+=a[cnt2];
			a[cnt1]-=a[cnt2];
			cnt2--;
		}else{
			if(c[cnt1]!=c[cnt2]) ans+=a[cnt1];
			cnt1++;
			cnt2--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
