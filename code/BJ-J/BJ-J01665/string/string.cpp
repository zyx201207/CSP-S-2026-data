#include<bits/stdc++.h>
using namespace std;
long long a[500005];
char c[500005];
long long L=0;
long long maxai=0;
vector<char> s(200002505);
//a[i]!=a[l-i+1] ans++;
int main(){
    freopen("string.in","r",stdin);//差点忘了
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        L+=a[i];
    }
    if(n==1){
        cout<<0;
        return 0;
    }else if(n==2 && c[1]==c[2]){
        cout<<0;
        return 0;
    }else if(n==2){
        long long minn=1e18;
        for(int i=1;i<=n;i++){
            minn=min(minn,a[i]);
        }
        cout<<minn;
        return 0;
    }
    long long cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++)s[++cnt]=c[i];
    }
    long long ans=0;
    for(int i=1;i<=L/2;i++){//设l=5
        //i=1 i<=2 对对对
        if(s[i]!=s[L-i+1]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
//68pts
