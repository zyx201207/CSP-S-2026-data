#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
char c[N];
ll a[N],i,n,ans,l,r,cnt;
struct Node{
	char ch;
	ll s;
}S;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    l=1;r=n;
    for(i=1;i<=n;i++) cin>>a[i]>>c[i];
    while(l<=r){
		cnt+=a[l];
		if(S.s!=0){
			if(S.s<cnt){
				if(S.ch!=c[l]) ans+=S.s;
				cnt-=S.s;
				S.s=0;
			}else{
				if(S.ch!=c[l])ans+=cnt;
				S.s-=cnt;
				cnt=0;
			}
		}
		while(cnt>0&&l<=r){
			if(cnt>a[r]){
				if(c[l]!=c[r]) ans+=a[r];
				cnt-=a[r];
				r--;
			}else{
				if(c[l]!=c[r]) ans+=cnt;
				S.s=a[r]-cnt;
				cnt=0;
				S.ch=c[r];
				r--;
			}
		}
		l++;
	}
	cout<<ans;
	return 0;
}
