#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans,cnt,h[10];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==0) cnt++;
    }
    if(cnt>n-m){
        cout<<0;
        return 0;
    }
    if(m==1){
        for(int i=1;i<=n;i++) ans=max(ans,a[i]);
        printf("%d",ans);
        return 0;
    }else if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        printf("%d",ans);
        return 0;
    }else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        printf("%d",ans);
        return 0;
    }else if(m==n-1){
        for(int i=1;i<=n;i++){
            int c;
            if(i!=1) c=a[1];
            else c=a[2];
            for(int j=2;j<=n;j++){
                if(j==i) continue;
                c=c&a[j];
            }
            ans=max(ans,c);
        }
        printf("%d",ans);
        return 0;
    }
    sort(a+1,a+1+n,greater<int>());
    if(a[1]<=4){
        for(int i=1;i<=n;i++){
            h[a[i]]++;
        }
        if(h[4]>=m){
            cout<<4;
        }else if(h[3]>=m) cout<<3;
        else if(h[3]+h[2]>=m) cout<<2;
        else if(h[3]+h[1]>=m) cout<<1;
        else cout<<0;
        return 0;
    }
    ans=a[1];
    for(int i=2;i<=m;i++) ans=ans&a[i];
    printf("%d",ans);
    return 0;
}

