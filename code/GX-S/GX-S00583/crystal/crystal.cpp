#include<bits/stdc++.h>
using namespace std;
long long t,n,m,a[500010],c,w[500010],ans,rans,cm,mm,mn=INT_MAX,cnt;
bool flag1,flag2,flag;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    cm = m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mm = max(mm,a[i]);
        mn = min(mn,a[i]);
        if(i==1) t = a[i];
        if(i==2) c = a[2] - a[1];
        if(a[i]!=t) flag1 = true;
        if(i>2&&a[i]-a[i-1]!=c) flag2 = true;
    }
    sort(a+1,a+1+n);
    if(!flag1){
        cout<<n<<endl;
    }else if(!flag2){
        sort(a+1,a+1+n);
        while(m>=0){
            m-=cnt*c;
            if(m>=0) ans++;
            cnt++;
        }
        cout<<ans+1<<endl;
    }else{
        for(int i=mn;i<=mm;i++){
            m = cm;
            ans = 0;
            for(int j=1;j<=n;j++){
                w[j] = i-a[j];
            }
            sort(w+1,w+1+n);
            //for(int j=1;j<=n;j++) cout<<w[j]<<" ";
            //cout<<endl;
            for(int j=1;j<=n;j++){
                //cout<<i<<":"<<w[i]<<endl;
                if(w[j]>=0){
                    m-=w[j];
                    if(m>=0) ans++;
                    else break;
                }
            }
            rans = max(rans,ans);
        }
        cout<<rans;
    }
    return 0;
}
