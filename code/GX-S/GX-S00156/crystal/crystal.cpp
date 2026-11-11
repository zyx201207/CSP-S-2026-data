#include<bits/stdc++.h>
using namespace std;
double a[500010];
int n;
long long m;
double fp[500010][19];
double fx[500010][19];
void inti(int n){
    for(int i=1;i<=n;i++){
        fp[i][0]=a[i];
        fx[i][0]=a[i];
    }
    int k=log2(n);
    for(int j=1;j<=k;j++){
        for(int i=1;i<=n-(1<<j)+1;i++){
            fx[i][j]=max(fx[i][j-1],fx[i+(1<<(j-1))][j-1]);
            fp[i][j]=(fp[i][j-1]+fp[i+(1<<(j-1))][j-1])/2;
        }
    }
    return ;
}
/*long long cl(double a){
    if(a-(long long)a!=0){
        return (long long)a+1;
    }else{
        return (long long)a;
    }
}*/
double RMQx(int l,int r){
    int k=log2(r-l+1);
    double x=max(fx[l][k],fx[r-(1<<k)+1][k]);
    return x;
}
double RMQp(int l,int r){
    int k=log2(r-l+1);
    /*int sum=0;
    int i=l;
    while(k){
        sum+=(1<<k)*fp[i][k];
        i+=(1<<k);
        k=log2(r-i+1);
    }
    return sum/(r-l+1);*/
    if(pow(2,k)==r-l+1){
        return fp[l][k];
    }else{
        return ((1<<k)*fp[l][k]+(r-l+1-(1<<k))*RMQp(l+(1<<k),r))/(r-l+1);
    }
}
long long RMQc(int l,int r){
    return ceil((r-l+1)*(RMQx(l,r)-RMQp(l,r)));
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    bool f=true;
    int c=a[2]-a[1];
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=c) f=false;
    }
    if(m==0){
        int l=1;
        int r=2;
        int mx=0;
        while(r<=n&&l<=r){
            //cout<<l<<r;
            mx=max(mx,r-l+1);
            if(a[l]!=a[r]){
                r++;
                l=r-1;

            }else{
                r++;
            }

        }
        cout<<mx;
        return 0;
    }
    if(f){
        for(int i=n;i>=1;i--){
            double s=(a[1]+a[i])/2*i;
            if(s+m>a[i]*i){
                cout<<i;
                return 0;
            }
        }
    }
    inti(n);
    /*cout<<RMQc(1,5);*/
    for(int l=n;l>=1;l--){
        long long mn=0x3f3f3f3f3f3f3f3f;
        for(int i=1;i+l-1<=n;i++){
            //cout<<"l:"<<i<<"r:"<<i+l-1<<" "<<RMQc(i,i+l-1)<<"\n";
            mn=min(mn,RMQc(i,i+l-1));
        }
        if(m>=mn){
            //cout<<mn;
            cout<<l;
            return 0;
        }
    }
    //printf("%.2f",a);
    return 0;
}
