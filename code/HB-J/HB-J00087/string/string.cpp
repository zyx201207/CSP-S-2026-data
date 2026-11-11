#include <bits/stdc++.h>
using namespace std;
struct node{
    int v;
    char c;
}a[200010];
int n;
string s;
long long cnt,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d%s",&a[i].v,&a[i].c);
       while(a[i].v--){
            s+=a[i].c;
        }
    }
    int len=s.size();
    for(int i=0;i<=len/2;i++){
        if(s[i]!=s[len-i-1])ans++;
    }
    cout<<ans;
    return 0;
}
