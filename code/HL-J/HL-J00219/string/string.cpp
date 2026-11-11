#include <bits/stdc++.h>
using namespace std;
char c[100000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long cnt=0,sum=0;
    for(int i=0;i<n;i++){
        long long a;
        char k;
        cin>>a>>k;
        for(int j=cnt;j<cnt+a;j++)c[j]=k;
        cnt+=a;
    }
    for(int i=0,j=cnt-1;i<j;i++,j--){
        if(c[i]!=c[j])sum++;
    }
    cout<<sum;
    return 0;
}
