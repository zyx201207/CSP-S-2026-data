#include<bits/stdc++.h>
#define re register
using namespace std;
typedef long long ll;
int n;
ll a,l;
ll sum;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    while(n--){
        scanf("%lld",&a);
        cin>>c;
        for(re int i=1;i<=a;i++)s+=c;
        l+=a;
    }
    for(re ll i=0;i<l/2;i++){
        if(s[i]!=s[l-1-i])sum++;
    }
    printf("%lld",sum);
    return 0;
}
