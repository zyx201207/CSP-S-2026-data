#include<bits/stdc++.h>
using namespace std;
//map <long long,long long>mp;
struct node{
    long long x,y,c,d,cs;
    bool operator <(const node &z)const{
        if(z.x!=x){
            return x<z.x;
        }
    }
};
long long n,m,max1=0,m1;
bool f=1;
long long ans=0,tans=0;
node a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
        a[i].y++;
        if(a[i].y>max1){
            max1=a[i].y,m1=a[i].x;
        }
    }
    if(m==0){
        cout<<max1;
        return 0;
    }
    sort(a,a+n);
    for(int i=1;i<=n;i++){
        if(i==1)a[i].c=0;
        else{
            a[i].c=a[i].x-a[i-1].x;
            a[i].cs=a[i-1].cs+a[i].c;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            long long d=a[j].cs-a[i-1].cs;

            long long tmp=j-i;
            if(d>m){
                if(tmp>tans)tans=tmp;
                //cout<<d<<" "<<ans<<"\n";
                if(tans>ans)ans=tans;
                break;
            }
            else if(d==m){
                if(tmp+1>tans)tans=tmp+1;
                if(tans>ans)ans=tans;
                //cout<<d<<" "<<ans<<"\n";
                break;
            }

            tans=tmp;
            if(tans>ans)ans=tans;
            //cout<<d<<" "<<ans<<"\n";
        }
    }
    cout<<ans;
    return 0;
}
