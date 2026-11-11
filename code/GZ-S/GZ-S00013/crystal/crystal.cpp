//GZ-S00013 龙里县生态城实验学校 吴沛珊
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5;
ll n,m,ans=0;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
    //sort(q.(),q.begin());
	for(int i=n;i>0;i--){
        for(int j=i-1;j>=0;j--){
            if(a[i]<a[j]) swap(a[i],a[j]);
        }
	}

	ll le=5e5,re=-1,k=1;
	int t[N];
	for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]==a[j]){
                le=min(le,a[i]);
                t[k]++;
                if(a[i]>le){
                    le=a[i];
                    k++;
                    t[k]=1;
                }
                re=max(re,a[j]);
                t[k]++;
            }
        }
	}
	ll l=1,r=n;
	ll mid=(l+r)/2;
	if(a[le]!=0) mid=a[le]-1;

	for(int i=1;i<=k;i++){
        for(int j=i;j<=k;j++){
            if(t[i]>t[j]) ans=t[i];
            else ans=t[j];
        }
	}
	if(ans!=0) ans--;
	while(m!=0 && mid!=0){
        ll q=a[mid]-a[mid-1],h=a[mid+1]-a[mid];
        if( (q<m || h<m ) && (a[mid]==a[mid+1] || a[mid-1]<=0 ) ){
            m-=q;
			ans++;
        }else if(q<m || h<m){
            m-=min(q,h);
           	ans++;
		}else if(max(q,h)<m){
            m-=max(q,h);
            ans++;
        }else break;
        mid--;
        if(mid<=0) break;
	}
	cout<<ans;
	return 0;
}
