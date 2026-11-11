#include<bits/stdc++.h>
using namespace std;
const int N=500001;
long long n,m,a[N],x,j,ans=0,minn=N;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);//cout<<1;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        minn=min(minn,a[i]);
    }
    //sum[0]=0;
    for(int i=1;i<=n;i++){
        a[i]-=minn;//cout<<i;
        //sum[i]=sum[i-1]+a[i];
        //cout<<sum[i]<<endl;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        x=m,j=i;
        while(j>0&&x>=a[i]-a[j]){
			x-=a[i]-a[j];
			j--;
		}
        ans=max(ans,i-j);
    }//cout<<1;
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
