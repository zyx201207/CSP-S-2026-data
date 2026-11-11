#include<bits/stdc++.h>
using namespace std;
int n;
char z[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long l=1;
    for(int i=1;i<=n;i++){
        long long a;
        char s;
        cin>>a>>s;
        for(int j=l;j<l+a;j++){
            z[j]=s;
        }
        l+=a;
    }
    int ans=0;
    int j=l-1;
    for(int i=1;i<l;i++){
        if(z[i]!=z[j]){
            ans++;
        }
        j--;
    }
    int trueans=ans/2;
    cout<<trueans;
    return 0;
}
