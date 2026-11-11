#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,q,x,y,a[N],cnt=1,xx,yy,cnt1,cnt2;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n%2!=0){
        q=n/2+1;
        x=q-1;
        y=q+1;
        while(1){
            xx=abs(abs(a[q])-abs(a[x]));
            yy=abs(abs(a[q])-abs(a[y]));
            if(xx>m&&yy>m){
                break;
            }if(x<1&&y>n){
                break;
            }
            if(x>=1&&xx<=m&&y<=n&&yy<=m){
                if(xx<yy){
                    m-=xx;
                    x--;
                    cnt++;
                }else{
                    m-=yy;
                    y++;
                    cnt++;
                }
            }else if(y<=n&&yy<=m){
                m-=yy;
                y++;
                cnt++;
            }else if(x>=1&&xx){
                m-=xx;
                x--;
                cnt++;
            }else break;
        }
    }
    else{
        q=n/2;
        x=q-1;
        y=q+1;
        while(1){
            xx=abs(abs(a[q])-abs(a[x]));
            yy=abs(abs(a[q])-abs(a[y]));
            if(xx>m&&yy>m){
                break;
            }if(x<1&&y>n){
                break;
            }
            if(x>=1&&xx<=m&&y<=n&&yy<=m){
                if(xx<yy){
                    m-=xx;
                    x--;
                    cnt1++;
                }else{
                    m-=yy;
                    y++;
                    cnt1++;
                }
            }else if(y<=n&&yy<=m){
                m-=yy;
                y++;
                cnt1++;
            }else if(x>=1&&xx){
                m-=xx;
                x--;
                cnt1++;
            }else break;
        }x=q-1;
        y=q+1;
        while(1){
            xx=abs(abs(a[q])-abs(a[x]));
            yy=abs(abs(a[q])-abs(a[y]));
            if(xx>m&&yy>m){
                break;
            }if(x<1&&y>n){
                break;
            }
            if(x>=1&&xx<=m&&y<=n&&yy<=m){
                if(xx<yy){
                    m-=xx;
                    x--;
                    cnt2++;
                }else{
                    m-=yy;
                    y++;
                    cnt2++;
                }
            }else if(y<=n&&yy<=m){
                m-=yy;
                y++;
                cnt2++;
            }else if(x>=1&&xx){
                m-=xx;
                x--;
                cnt2++;
            }else break;
        }
        cnt=max(cnt1,cnt2)+1;
    }
    cout<<cnt;
    return 0;
}
