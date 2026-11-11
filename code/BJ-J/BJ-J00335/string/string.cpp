#include<bits/stdc++.h>
#include<string>

using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long qian[n+1]={};
    char m[n+1]={};
    long long lon=0,cnt=0;
    for(int i=1;i<=n;i++){
        long long a;
        cin>>a>>m[i];
        qian[i]=lon;
        lon+=a;
    }
    long long indx=n,inde=1;
    for(long long i=1;i<=lon/2;i++){
        if(lon-i<qian[indx]){
            indx--;
        }
        if(i>qian[inde+1]){
            inde++;
        }
        if(m[inde]!=m[indx]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
