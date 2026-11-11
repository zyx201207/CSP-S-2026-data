#include<bits/stdc++.h>
using namespace std;
namespace FZT{
typedef long long ll;
const int N=2e5+5;
ll n,a[N],cnt,len,ans,pre[N],cur[N];
char c[N];
void Main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cnt++;
		cin>>a[cnt]>>c[cnt];
		len+=a[cnt];
		if(c[cnt]==c[cnt-1]) a[cnt-1]+=a[cnt],cnt--;
	}
	int i=1,j=cnt;
	ll now=0,l=a[i],r=a[j];
	while(i<j){
		ll delta=min(l-now,r-now);
		ans+=delta*(c[i]!=c[j]);
		if(l<r){
			i++;
			l+=a[i];
		}
		else if(l>r){
			j--;
			r+=a[j];
		}
		else{
			i++;
			j--;
			l+=a[i];
			r+=a[j];
		}
		now+=delta;
	}
	cout<<ans;
}}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	FZT::Main();
	return 0;
}
