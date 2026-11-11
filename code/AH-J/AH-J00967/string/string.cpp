#include<bits/stdc++.h>
using namespace std;
int n;
long long sum,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    int x;
    char c;
    string s="";
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        cin>>c;
        for(int i=1;i<=x;i++){
            s+=c;
        }
        sum+=x;
    }
    for(long long i=1;i<=sum/2;i++){
        if(s[i-1]!=s[sum-i-1]){
            ans++;
        }
    }
    printf("%lld",ans);
    return 0;
}
