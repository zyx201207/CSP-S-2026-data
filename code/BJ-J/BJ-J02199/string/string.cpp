#include <bits/stdc++.h>
using namespace std;
string a,b;
bool f=1;
long long sum,ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        long long cnt;
        string s;
        cin>>cnt>>s;
        sum+=cnt;
        for(long long j=0;j<cnt;j++){
            a+=s;
        }
    }
    //cout<<a<<" "<<sum;
    for(long long i=0;i<sum;i++){
        //cout<<i<<" "<<sum-i-1<<endl;
        if(a[i]!=a[sum-i-1]){

            f=0;
            break;
        }
    }
    if(f==1){

        cout<<0;
        return 0;
    }
    for(long long i=0;i<sum/2;i++){
        if(a[i]!=a[sum-i-1]) ans++;
    }
    cout<<ans;
    return 0;
}
