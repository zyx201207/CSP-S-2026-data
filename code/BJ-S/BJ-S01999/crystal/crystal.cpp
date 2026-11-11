#include <bits/stdc++.h>
using namespace std;

struct cha{
    int num;
    bool zf;
};

bool cmp(cha x,cha y){
    if(x.zf!=y.zf) return x.zf<y.zf;
    else return x.num<y.num;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    double p=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        p+=a[i];
    }
    p/=n;
    double mini=abs(a[0]-p),q=a[0];
    for(int i=1;i<n;i++){
        if(abs(a[i]-p)<mini){
                mini=abs(a[i]-p);
                q=a[i];
        }
    }
    cha b[n];
    for(int i=0;i<n;i++){
        b[i].num=abs(a[i]-q);
        if(a[i]-q>0) b[i].zf=true;
        else b[i].zf=false;
    }
    sort(b,b+n,cmp);
    int sum=0,ans=0,l=0;
    while(sum<m){
        if(b[l].zf==false){
            if((sum+b[l].num)<=m){
                sum+=b[l].num;
                l++;
                ans++;
            }
            else break;
        }
        else{
            if(sum+b[l].num*ans<=m){
                sum+=b[l].num*ans;
                l++;
                ans+=1;
            }
            else break;
        }
    }
    cout<<ans;
    return 0;
}