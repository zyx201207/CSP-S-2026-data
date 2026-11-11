#include<bits/stdc++.h>
using namespace std;
/*
int n,m,sum,ans;
struct node{
    int n;
    int pre;
}a[100005];
bool cmp(node x,node y){
    return x.pre<y.pre;
}
int main(){
    cin>>n>>m;
    sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].n;
        sum+=a[i].n;
    }
    sum/=n;
    cout<<sum<<endl;
    for(int i=1;i<=n;i++){
        a[i].pre=a[i].n-sum;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(a[i].pre<=0 && m>=abs(a[i].pre)){
            m-=a[i].pre;ans++;
        }
    }
    cout<<ans;
}*/
const int N=500010;
long long n,ans=0,t;
long long nw;
long long m;
struct node{
    int a;
    int pre;
    bool bo=false;
}s[N];
bool cmp(node x,node y){
    return x.a<y.a;
}/*
void shuaxin(int x,int y){
    for(int i=1;i<=x;i++){
        if(s[i].bo==true){
            s[i].a=y;
            //cout<<i<<s[i].a<<" ";
        }
    }
    nw=y;
}*/
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i].a;
    }
    sort(s+1,s+n+1,cmp);
    /*for(int i=1;i<=n;i++){
        cout<<s[i].a;
    }*/
    for(int i=1;i<=n;i++){
        s[i].pre=s[i+1].a-s[i].a;
        //cout<<s[i].pre<<" ";
        //(s[i].pre*(t+1)<=m && m>0)|| (s[i].pre*(t+1)==0 && m<=0)
        if(s[i].pre*(t+1)<=m and m>=0){
            t++;
            //cout<<m<<i<<"in"<<endl;
            m=m-s[i].pre*t;
            s[i].bo=true;
            s[i].a=s[i+1].a;
            nw=s[i].a;
        }else{
            if(m==0 and s[i].pre==0){
                t++;
                s[i].bo=true;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(s[i].a==nw || s[i].bo==true){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
