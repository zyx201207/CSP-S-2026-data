#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005],c[500005],s[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ll n,m,sum=0,ma=1,ans=0,ok=1,ok2=1;
	scanf("%lld%lld",&n,&m);
	if(n==1){printf("1");return 0;}
	scanf("%lld",&a[1]);
	for(int i = 2;i <= n;++i){
	    scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i = 1;i < n;++i){
        c[i]=a[i+1]-a[i];
	    if(a[i]!=i){ok=0;}
	    if((c[i]!=c[i-1])&&(i>1)){ok2=0;}
	}
	if(ok){
        for(ll i = 1;i <= n;++i){
            if(i*(i+1)/2 > m){
                printf("%lld",i);
                return 0;
            }
        }
        printf("%lld",n);
        return 0;
	}
	if(ok2){
        double d = m * 1.0 / c[1];
        for(ll i = 1;i <= n;++i){
            if(i*(i+1)/2 > d){
                printf("%lld",i);
                return 0;
            }
        }
        printf("%lld",n);
        return 0;
	}
	s[0]=0;
	for(int i = 1;i < n;++i){
        s[i]=c[i]+s[i-1];
	}

	//for(int i = 1;i < n;++i){
    //    cout << c[i] << " ";
	//}
	//cout << '\n';
	//for(int i = 1;i < n;++i){
    //    cout << s[i] << " ";
	//}
	//cout << '\n';

	for(int i = n-1;i > 1;--i){
        sum=0;ans=1;
        if(i+1<ma){break;}
        for(int j = i-1;j>=0;--j){
            if((sum+s[i]-s[j])<=m){++ans;sum+=(s[i]-s[j]);}
            else{break;}
            //cout << sum << " " << i << j << " ";
        }
        //cout << ans << '\n';
        ma=max(ma,ans);
	}
	printf("%lld",ma);
    return 0;
}
