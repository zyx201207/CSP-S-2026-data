#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool f=1;
ll n,m,d,a[500005],c[500005],b[500005],t,cnt,ans=LLONG_MIN;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==2)d=abs(a[i+1]-a[i]);
        if(i>=3){
            if(abs(a[i+1]-a[i])!=d)f=0;
        }
	}
	if(f==1){
        ll lv=0;
        ll t=m;
        while(t){
            if(t<lv)break;
            t-=lv;
            lv++;
        }
        cout<<lv;
        return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
        t=m;
        cnt=0;
        for(int j=1;j<=i;j++){
            b[j]=a[i]-a[j];
        }
        for(int j=i;j>=1&&t>=b[j];j--){
            t-=b[j];
            cnt++;
        }
        ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
