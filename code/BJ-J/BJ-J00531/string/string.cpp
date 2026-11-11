#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
struct b{
    long long a;
    char c;
}s[200005];
string s1,s2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
        for(int j=1;j<=s[i].a;j++){
            s1+=s[i].c;
        }
        s2+=s1;
        int q=(s2.size())/2;
        for(int j=1;j<=q;j++){
            if(s2[j]!=s2[q-j]){
                s2[q-j]=s2[j];
                cnt++;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
