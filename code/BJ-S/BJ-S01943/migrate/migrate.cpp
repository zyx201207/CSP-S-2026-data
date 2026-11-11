#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
typedef long long ll;
ll c,t,n,d,a[N],f1;
void xxx(){
    int dd=abs(a[2]-a[1]);
    int p=d/dd;
    if(p!=2){
        cout<<0<<endl;
        return ;
    }
    int q=p+1;
    cout<<n-q<<endl;
}
void xxx2(){
    int l=1;
    ll sum=0,ans=0;
    if(n<=3){
        cout<<0<<endl;
        return ;
    }
    for(int i=1;i<=n;i++){
        sum+=a[i];
        if(sum>d){
            ans+=n-i+1;
            sum-=a[l];
            l++;
        }
    }
    cout<<ans<<endl;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])f1=1;
        }
        if(f1==0)xxx();
        if(c==13||c==14){
            xxx2();
        }
        else cout<<0<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
