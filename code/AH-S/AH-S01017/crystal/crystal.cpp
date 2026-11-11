#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long tr[500005][25];
int lg2[500005];
int ans=1;
long long upset(int l,int r){
    long long sum=0;
    for(int i=l;i<=r;){
        sum+=tr[i][lg2[r-i+1]];
        i+=(1<<lg2[r-i+1]);
    }
    return sum;
}
void work(){
    for(int i=2;i<=n;i++){
        int l=1,r=i;
        while(l<=r){
        	if((i-l+1)<=ans){
        		break;
			}
            int mid=(l+r)>>1;
            if((1ll*upset(mid,i-1)+1ll*m)>=(1ll*a[i]*(i-mid))){
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        ans=max(ans,i-r);
    }
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    scanf("%d %lld",&n,&m);
    for(int i=2;i<=n;i++){
        lg2[i]=lg2[i/2]+1;
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        tr[i][0]=a[i];
	}
    for(int j=1;j<=20;j++){
        for(int i=1;(i+(1<<j)-1)<=n;i++){
            tr[i][j]=tr[i][j-1]+tr[i+(1<<(j-1))][j-1];
        }
    }
    work();
    printf("%d",ans);
	return 0;
}
