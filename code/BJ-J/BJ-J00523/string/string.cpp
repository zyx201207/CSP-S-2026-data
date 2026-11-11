#include <bits/stdc++.h>
using namespace std;
long long n,ans;
struct st{
    long long a;
    char c;
}s[100005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld %c",&s[i].a,&s[i].c);
    }
    long long k=0,q=0;
    for(long long i=1,j=n;i<j;){
        if(k==0){
            k=s[i].a;
        }
        if(q==0){
            q=s[j].a;
        }
        if(k>q){
            k-=q;
            if(s[i].c!=s[j].c){
                ans+=q;
            }
            q=0;
            j--;
        }
        else if(k==q){
            if(s[i].c!=s[j].c){
                ans+=q;
            }
            k=q=0;
            i++,j--;
        }
        else{
            q-=k;
            if(s[i].c!=s[j].c){
                ans+=k;
            }
            k=0;
            i++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
