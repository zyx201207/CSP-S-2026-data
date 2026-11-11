#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(ll p1,ll p2){
    return p1>p2;
}
ll a[500005],cnt[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m,maxn=1;
    cin>>n>>m;
    for (ll i = 1; i <= n; i++)
    {
        cin>>a[i];
        //b[i]=a[i];
    }
    sort(a+1,a+n+1);
    ll temp=a[2]-a[1],bt=0;
    for (ll i = 2; i <= n; i++)
    {
        if(a[i]-a[i-1]!=temp){
            bt=1;
            break;
        }
    }
    if(bt==0&&temp==1){
		ll nm=0,p=1;
		while(nm+abs(temp)<=m){
			ll tmp=nm;
			//cout<<tmp<<" ";
			nm=tmp+tmp+abs(temp);
			//cout<<temp<<" "<<tmp<<" "<<nm<<endl;
			p++;
		}
		cout<<p;
		return 0;
	}
    else if(bt==0&&n>5000){
        ll nm=1,p=1,maxx=0;
        for(ll i=0;i<temp;i++){
			nm=i,p=1;
			while(nm+abs(temp)<=m){
				ll tmp=nm;
				//cout<<tmp<<" ";
				nm=tmp+tmp+abs(temp);
				//cout<<temp<<" "<<tmp<<" "<<nm<<endl;
				p++;
			}
			maxx=max(maxx,p);
		}
        //if(nm==m) p++;
        cout<<maxx;
        return 0;
    }
    sort(a+1,a+n+1);
    for (ll l = a[1]; l <= a[n]; l++)
    {
        memset(cnt,-1,sizeof(cnt));
        for (ll i = 1; i <= n; i++)
        {
            if(a[i]<=l){
                cnt[i]=l-a[i];
            }
        }
        sort(cnt+1,cnt+n+1,cmp);
        ll num=0;
        while (cnt[num+1]!=-1)
        {
            num++;
        }
        sort(cnt+1,cnt+num+1);
        ll sum=0;
        for (ll i = 1; i <= num; i++)
        {
            //cout<<cnt[i]<<endl;//000000
            if(sum+cnt[i]<=m){
                sum+=cnt[i];
                maxn=max(maxn,i);
            }
        }
        
        
    }
    cout<<maxn;
    return 0;
}
