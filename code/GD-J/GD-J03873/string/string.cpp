#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

int n,cnt;
int a[N];
char c[N];
bool vis[30];
ll ans;
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(!vis[c[i]-'a']){
			++cnt;
			vis[c[i]-'a']=1;
		}
	}
	if(cnt==1){
		cout<<0;
		return 0;
	}
	int i=1,j=n;
	while(i<j){
		ans+=(c[i]==c[j]?max(a[i],a[j])-min(a[i],a[j]):max(a[i],a[j]));
		if(a[i]<a[j]){
			int res=a[j]-a[i],sum=0,pos=i+1;
			while(pos<j&&sum+a[pos]<=res){
				sum+=a[pos];
				if(c[pos]==c[j]) ans-=a[pos];
				++pos;
			}
			if(sum<res){
				a[pos]-=(res-sum);
				if(c[pos]==c[j]){
					ans-=(res-sum);
				}
			}
			i=pos;
			--j;
		}
		else if(a[i]==a[j]){
			++i,--j;
		}
		else {
			int res=a[i]-a[j],sum=0,pos=j-1;
			while(pos>i&&sum+a[pos]<=res){
				sum+=a[pos];
				if(c[pos]==c[i]) ans-=a[pos];
				--pos;
			}
			if(sum<res){
				a[pos]-=(res-sum);
				if(c[pos]==c[i]){
					ans-=(res-sum);
				}
			}
			++i;
			j=pos;
		}
	}
	cout<<ans;
	return 0;
}
