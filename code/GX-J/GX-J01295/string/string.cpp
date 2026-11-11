#include<bits/stdc++.h>
using namespace std;
int n,a,ansq,ansh,t;
long long ans,sum;
char c;
string m;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        ans+=a;
        for(int l=1;l<=a;l++){
            m+=c;
        }
    }
    for(int i=ans-1,j=0;i>=j;i--,j++){
        if(m[i]!=m[j]){
            sum++;
        }
    }
    printf("%lld",sum);
    return 0;
}
