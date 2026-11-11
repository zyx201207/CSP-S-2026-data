#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2*1e5+5;
ll n;
ll a[N],len;
char c[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	ll l=n/2,r=len/2;
	ll ans=0;
	ll idx=a[1]-a[n],id=1;
	while(id<=r){
		if(idx<0){
			idx=abs(idx);
			if(c[id]!=c[n-id+1])ans+=idx;
			for(int j=1;;j++){
				if(a[id+j]-idx<0){
					a[id+j]=0;
					idx=a[id+j]-idx;
					if(c[id]!=c[n-id+1])ans+=a[id+j];
					if(idx==0)break;
				}else if(a[id+j]-idx>0){
					if(c[id+j]!=c[n-id-j+1])ans+=abs(idx);
					a[id+j]-=idx;
					id+=j;
					idx=0;
					break;
				}else if(idx==0){
					break;
					id+=j;
				}
			}
		}else if(idx>0){
			idx=abs(idx);
			if(c[id]!=c[n-id+1])ans+=idx;
			for(int j=1;;j++){
				if(a[n-(id+j)+1]-idx<0){
					a[n-(id+j)+1]=0;
					idx=abs(a[n-(id+j)+1]-idx);
					if(c[id+j]!=c[n-(id+j)+1])ans+=a[id+j];
					if(idx==0)break;
				}else if(a[n-(id+j)+1]-idx>0){
					if(c[id]!=c[n-id-j+1])ans+=abs(idx);
					a[n-(id+j)+1]-=idx;
					id+=j;
					idx=0;
					break;
				}else if(idx==0){
					break;
					id+=j;
				}
			}
		}else if(idx==0){
			id+=a[id];
		}
		idx=a[id]-a[n-id+1];
	}
	cout<<ans;
	return 0;
}
