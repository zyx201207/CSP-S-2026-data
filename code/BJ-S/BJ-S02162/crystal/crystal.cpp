#include <bits/stdc++.h>
using namespace std;

long long n,m,ans=0;//numberofcrystal,maxiumadds,answer
long long a[500005],b[500005],su[500005];//yuanshuzu,qianzhuishuzu,leijiashuzu

//qiazhuihe 33
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        b[i]=a[i]-a[i-1];
    }

    //daoxubianli"i","while"bianli"k":b[i]+b[i-1]+...+b[i-k]<=m,max(k)
    for(long long i=n;i>=1;i-=1){
        long long k=0,sum=0,sum2=0,addsum=0;
        while(1){
            long long x=i-k;
            if(x<1) break;
            addsum=b[x]+sum2;
            sum+=addsum;
            sum2=addsum;
            if(sum>m)break;
            k++;
        }
        ans=max(ans,k+1);
    }
    cout<<ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}