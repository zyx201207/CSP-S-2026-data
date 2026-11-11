#include<iostream>
#include<algorithm>
using namespace std;
using ll=long long;
ll n,a[200010],ans;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(ll i=1,si=a[1],j=n,sj=a[n];i<j;){
		if(c[i]!=c[j])ans+=min(si,sj);
		if(si<sj){
			sj-=si;
			si=0;
		}
		else{
			si-=sj;
			sj=0;
		}
		if(si==0){
			i++;
			si+=a[i];
		}
		if(sj==0){
			j--;
			sj+=a[j];
		}
	}
	cout<<ans;
	return 0;
}
