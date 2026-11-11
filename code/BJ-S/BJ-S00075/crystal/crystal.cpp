#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[500009];
long long c[500009];
long long ans=0;
long long maxx=-1e9;
long long s[500020];
bool ok=false;
bool flag=true;
bool cmp(long long x,long long y){
    return x<y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=2;i<=n;i++){
        s[i]=a[i]-a[i-1];
    }
    for(int i=3;i<=n;i++){
        if(s[i]!=s[i-1]) flag=false;
    }
    if(n==1){
        cout<<"1";
        flag=false;
    }
    else if(n==2){
        if(a[2]-a[1]<=m){
            cout<<"2";
        }
        else cout<<"1";
        flag=false;
    }
    else if(flag==true){
        long long sum=0;
        for(int i=1;i<=(n-1);i++){
            sum+=i*(s[2]-s[1]);
            if(sum>m){
                cout<<i;
                ok=true;
                break;
            }
        }
        if(ok==false){
            cout<<n;
        }
    }
    else{
		long long m1=m;
        for(int i=a[1];i<=a[n];i++){
            for(int j=1;j<=n;j++){
                if(a[j]>i&&((i-a[j])>m1)) break;
                else if(a[j]<=i&&((i-a[j])<=m1)){
                    ans++;
                    m1-=(i-a[j]);
                }
            }
            maxx=max(ans,maxx);
            ans=0;
            m1=m;
        }
        cout<<maxx;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
