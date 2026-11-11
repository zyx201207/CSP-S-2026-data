#include<bits/stdc++.h>
using namespace std;
const long long N=1e9+5;
int n;
long long sum=1;
char s[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char c;
        int a;
        cin>>a>>c;
        for(int j=sum;j<a+sum;j++){
            s[i]=c;
        }
        sum+=a;
    }
    cout<<0;
    return 0;
}
