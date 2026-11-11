#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fo(i,j,k) for(register int i=j;i<=k;i++)
const int N=2e5,M=1<<20+2;
int n,m,x,y,k,cnt,ans,a[N],s[N],ma,z[25];
bool chose[M][20];
char c[N];
void foor(){
    fo(z_1,0,1)fo(z_2,0,1)fo(z_3,0,1)fo(z_4,0,1)fo(z_5,0,1)fo(z_6,0,1)fo(z_7,0,1)fo(z_8,0,1)fo(z_9,0,1)fo(z_10,0,1)
    fo(z_11,0,1)fo(z_12,0,1)fo(z_13,0,1)fo(z_14,0,1)fo(z_15,0,1)fo(z_16,0,1)fo(z_17,0,1)fo(z_18,0,1)fo(z_19,0,1)fo(z_20,0,1){
        int sum=z_1+z_2+z_3+z_4+z_5+z_6+z_7+z_8+z_9+z_10+z_11+z_12+z_13+z_14+z_15+z_16+z_17+z_18+z_19+z_20;
        if(sum==m){
            int cur=0;
            if(z_1==1)z[++cur]=1;if(z_2==1)z[++cur]=2;if(z_3==1)z[++cur]=3;if(z_4==1)z[++cur]=4;if(z_5==1)z[++cur]=5;
            if(z_6==1)z[++cur]=6;if(z_7==1)z[++cur]=7;if(z_8==1)z[++cur]=8;if(z_9==1)z[++cur]=9;if(z_10==1)z[++cur]=10;
            if(z_11==1)z[++cur]=11;if(z_12==1)z[++cur]=12;if(z_13==1)z[++cur]=13;if(z_14==1)z[++cur]=14;if(z_15==1)z[++cur]=15;
            if(z_16==1)z[++cur]=16;if(z_17==1)z[++cur]=17;if(z_18==1)z[++cur]=18;if(z_19==1)z[++cur]=19;if(z_20==1)z[++cur]=20;
            int cnt=a[z[1]];
            //cout<<cur<<"-"<<cnt;
            for(int i=2;i<=m;i++) cnt&=a[z[i]];
            //cout<<cnt<<endl;
            ma=max(ma,cnt);
        }

    }
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    fo(i,1,n) cin>>a[i],ma=max(a[i],ma);
    if(m==1) cout<<ma;
    else if(m==2){
        ma=0;
        fo(i,1,n)fo(j,i+1,n){
            ma=max((int)(a[i]&a[j]),ma);
        }
        cout<<ma;
    }
    else if(n<=21){
        ma=0;
        foor();
        cout<<ma;
    }
    else {
        sort(a+1,a+n+1);
        cout<<a[n-m+1];
    }
    return 0;
}
