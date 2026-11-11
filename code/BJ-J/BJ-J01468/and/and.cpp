#include<bits/stdc++.h>
using namespace std;

long long n,m,a[2020],t[33],maxx=0;

bool cmp(int a,int b){
    return a>b;
}

int get2w(long long a){
    int cnt=0;
    while(a>0){
       a/=2;cnt++;
    }
    return cnt;
}
long long pow2(int a){
    long long n=1;
    for(int i=1;i<=a;i++) n*=2;
    return n;
}

void findmax(long long an,int lmt,int x,int ls){
    //cout<<an<<' '<<ls<<' ';

    if(ls==0){
        maxx=max(an,maxx);
        return;
    }
    if(x>lmt)return;

    for(int i=x+1;i<=lmt-ls;i++){
        findmax(an&a[i],lmt,i,ls-1);
    }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=1;i<=30;i++) t[i]=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[get2w(a[i])]++;
    }
    sort(a+1,a+n+1,cmp);
    if(m==1){
        cout<<a[1];
        return 0;
    }
    for(int i=30;i>=1;i--){
        //cout<<i;
        if(t[i]>=m){
            //cout<<114514;
            if(t[i]==m){
                maxx=pow2(20)-1;
                for(int i=1;i<=t[i];i++){
                    maxx=maxx&a[i];
                }
                break;
            }
            findmax(pow2(20)-1,t[i],0,m);
            break;
        }
        else{
            if(t[i]==0) continue;

            for(int j=1;j<=t[i];j++){
                a[j]=a[j]-pow2(i-1);
                //cout<<a[j]<<' ';
                t[get2w(a[j])]++;
            }
            t[i]=0;
            sort(a+1,a+n+1,cmp);
        }
    }
    cout<<maxx;

    return 0;
}
