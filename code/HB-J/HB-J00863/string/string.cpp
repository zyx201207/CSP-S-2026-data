#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2*1e5+5;
ll n,a[N],sum,cnt,s[N];
char c[N];
string str=" ";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%s",&a[i],&c[i]);
        sum+=a[i];
        s[i]=s[i-1]+a[i];
        for(int j=1;j<=a[i];j++)str+=c[i];
    }
    ll d=sum/2;
    for(ll i=1;i<=n;i++){
        if(s[i]>d)break;
        for(int j=1;j<=a[i];j++){
            if(str[s[i]+j-a[i]]!=str[sum-s[i]-j+a[i]+1])cnt++;
        }
    }
    cout<<cnt<<"\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
