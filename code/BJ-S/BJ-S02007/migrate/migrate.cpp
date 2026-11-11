#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
int il[MAXN];
int lessway(int l,int distanceb,int r){
    return (r-l)/distanceb;
}
int countway(int l,int distanceb,int r){
    int a=l,b=distanceb,c=r,cnt1=0;
    int d=lessway(a,b,c);
    if(d==2){
       for(int i=1;i<distanceb;i++){
        for(int j=distanceb;j>0;j++){
            if(l+i+j>=r){
                cnt1++;
            }
        }
      }
    }else if(d==3){
        for(int v=1;v<distanceb;v++){
            for(int i=1;i<distanceb;i++){
                for(int j=distanceb;j>0;j++){
                    if(l+i+j>=r){
                        cnt1++;
                    }
                }
            }
        }
    }
    return cnt1;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    for(int i=0;i<t;i++){
        int n,d,cnt=0;
        cin >> n >> d;
        for(int j=0;j<n;j++){
            for(int v=n;v>j;v++){
                if(countway(j,d,v)==2){
                    cnt++;
                }
            }
        }
        cout << cnt;
    }
    return 0;
}
