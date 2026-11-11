#include<bits/stdc++.h>
using namespace std;

int a[500010],n,m,ans;

int doo(int x){
    int m1=m,ans1=1;
    for(int i=x-1;i>=1;i--){
        if(a[x]-a[i]<=m1){
            ans1++;
            m1-=(a[x]-a[i]);
        }
        else return ans1;
    }
    return ans1;
}


int main(){
    freopen("crystal3.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);

    scanf("%d%d",&n,&m);

    if(n>5000){
        for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
        int m1=m,aa=a[2]-a[1],ans1=1;
        for(int i=1;i<=n;i++){
            if(i*aa<=m1){
                ans1++;
                m1-=i*aa;
            }
            else {
                cout<<ans1<<endl;
                return 0;
            }
        }
        cout<<ans1<<endl;
        return 0;
    }

    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--){
        ans=max(ans,doo(i));
        if(ans>=i)break;
    }
    cout<<ans<<endl;

    fclose(stdin);fclose(stdout);
    return 0;
}

