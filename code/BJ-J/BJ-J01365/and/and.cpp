#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn],num[maxn][40],ad[40],l[maxn],ans[40],sum;
int f(int i,int n){
    int cmp=31;
    while(n>0){
        num[i][cmp]=n&1;
        ad[cmp]+=n&1;
        cmp--;
        n>>=1;
    }
    return 0;
}
void ff(){
    for(int i=0;i<=31;i++){
    sum<<=1;
    sum+=ans[i];
    }
    return ;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        f(i,x);
    }
    int is=0,k=0;
    for(int i=0;i<=31;i++){
            k=0;
            for(int j=0;j<n;j++){
            if(ad[i]<m)continue;
            if(num[j][i]==1&&(is==0||is==i)&&ad[i]>=m){
                l[j]=1;is=i;ans[i]=1;
            }
            else if(num[j][i]==1&&l[j]==1&&ad[i]>=m){
                k++;
            }
            if(k>=m){ans[i]=1;}
        }
    }
ff();
cout<<sum;
    return 0;
}

