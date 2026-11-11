#include<iostream>
#include<string>
using namespace std;
long long a[200005],n,ans,sum;
char b[200005];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        sum+=a[i];
    }
    int p=1,q=n;
    while(1){
        if(a[p]>a[q]){
            if(b[p]!=b[q]){
                ans+=a[q];
            }
            a[p]-=a[q];
            q--;
        }
        if(a[q]>a[p]){
            if(b[p]!=b[q]){
                ans+=a[p];
            }
            a[q]-=a[p];
            p++;
        }
        if(a[p]==a[q]){
            if(b[p]!=b[q]){
                ans+=a[p];
            }
            p++;
            q--;
        }
        if(p>=q){
            break;
        }
    }
    cout<<ans;
    return 0;
}
