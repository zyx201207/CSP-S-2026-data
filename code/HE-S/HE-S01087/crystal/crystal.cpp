#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,m,a[N],s[N],b[N],mx,cha,mn=LONG_LONG_MAX;
long long tot,lft[N],cnt,lft2[N];
bool pd,pd1;
map<long long,long long> mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	pd=true;pd1=true;
	if(n==1){
        cout<<1;
        return 0;
	}
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) pd=false;
		if(i!=1){
            if(i==2){
                cha=abs(a[i]-a[i-1]);
            }
            if(abs(a[i]-a[i-1])!=cha){
                pd1=false;
            }
		}
		mp[a[i]]++;
		mx=max(a[i],mx);
	}
	sort(a+1,a+1+n);
	for(int i=n-1;i>=1;i--){
        lft[i]=lft[i+1]+(abs(a[i+1]-a[i]));
	}
	for(int i=1;i<=n;i++){
        lft2[i]=lft2[i-1]+lft[i];
	}
	if(pd){
        long long ssum=1;
        long long oo=1;
        while(1){
            if(m>=oo){
                m-=oo;
                ssum++;
                oo++;
            }else{
                break;
            }
        }
        cout<<ssum;
        return 0;
	}
	if(pd1){
        long long ssum=1,tt=1;
        for(long long i=n-1;i>=1;i--){
            if(m>=tt*cha){
                ssum++;
                m-=tt*cha;
                tt++;
            }else{
                break;
            }
        }
        cout<<ssum;
        return 0;
	}
	if(n<=6000){
            long long wzz=0,dq=0;
        for(int i=1;i<=n;i++){
                dq=0;
            for(int j=i-1;j>=1;j--){
                dq+=abs(a[i]-a[j]);
                if(m>=dq){
                        wzz=max(wzz,(long long)i-j+1);
                        //cout<<wzz<<' ';
                }else{
                    break;
                }
            }
        }
        cout<<wzz;
        return 0;
	}
	long long num=0,he=0,lef=0;
	for(int i=2;i<=n;i++){
           // lft[++cnt]=abs(a[i]-a[i-1]);
        lef+=(abs(a[i]-a[i-1]));
        he+=(i-1)*(abs(a[i]-a[i-1]));
        if(m>=he){
            num=max(num,1ll*i);
        }else{
            long long lf1=lef,he1=he-m;
            long long hj=lower_bound(lft2+1,lft2+1+n,he1)-lft2;
            if(lft2[hj-1]>=he1){
                if(i-hj+1>num) num=i-hj+1;
            }
        }
	}
	cout<<num;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/

