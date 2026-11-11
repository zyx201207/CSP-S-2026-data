#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int num,id;
}a[1000000];
bool cmp(node x,node y){
    /*if(x.id!=y.id){
        return x.id>y.id;
    }
    else{
        return x.num>=y.num;
    }*/
    return x.num>y.num;
}
int er(long long x,long long y){
    long long x2=0,y2=0,ans=0;
    while(x){
        x2=(x%2)*10+x2;
        x/=2;
    }
    while(y){
        y2=(y%2)*10+x2;
        y/=2;
    }
    int f=min(x2,y2);
    while(f){
        if(x2%10==y2%10){
            ans=ans*10+f%10;
        }
        else{
            ans*=10;
        }
        x2/=10;
        y2/=10;
        f/=10;
    }
    int num=0,c=0;
    while(ans){
        num+=(ans%10)*pow(2,c);
        ans/=10;
        c++;
    }
    return num;
}
int iser(int x){
    x+=1;
    while(x){
        if(x%2==0){
            x/=2;
        }
        else{
            return 0;
        }
    }
    return 1;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].num;
        a[i].id=iser(a[i].num);
    }
    sort(a+1,a+n+1,cmp);
    if(m==1){
        cout<<a[1].num;
        return 0;
    }
    int cnt=er(a[1].num,a[2].num);
    for(int i=3;i<=m;i++){
        cnt=er(cnt,a[i].num);
    }
    cout<<cnt;
    return 0;
}
