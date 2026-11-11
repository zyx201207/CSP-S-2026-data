#include<bits/stdc++.h>
using namespace std;
int s[10],n,m,a[1000100],s1,s2,ans1,ans2;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<10&&m<10){
        for(int i=1;i<=n;i++){
            s[1]=0,s[2]=0;
        for(int j=i;j<=n;j++){
            if(s[1]==0)s[1]=a[j];
            else if(s[1]==a[j])s[2]=0;
            else if(s[2]==0)s[2]=a[j];
        }
        if(s[1]==1)s1++;
        if(s[1]==2)s2++;
        if(s[2]==1)s1++;
        if(s[2]==2)s2++;
    }
    cout<<s1<<' '<<s2;
    return 0;
    }else{
        for(int i=1;i<=m;i++){
            for(int j=n;j>=1;j--)if(a[j]==i){
                cout<<j<<' ';
                break;
            }
        }
        return 0;
    }

}
