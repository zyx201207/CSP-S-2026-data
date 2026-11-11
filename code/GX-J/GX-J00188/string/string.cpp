#include<bits/stdc++.h>
using namespace std;
long long n,a,sum=0,ans=0,cnt=0;
string s;
char c,r[100000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>c;

        for(int j=cnt;j<cnt+a;j++){
            r[j]=c;

        }
        cnt+=a;
        sum+=a;
    }



    for(int i=0;i<sum/2;i++){
        if(r[i]!=r[sum-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
