#include<bits/stdc++.h>
using namespace std;
int n,a[200005],sum,sum2,num,minsum;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char c;
        cin>>a[i];
        num+=a[i];
        cin>>c;
        for(int j=1;j<=a[i];j++){
            s=s+c;
        }
    }
    s=' '+s;
    for(int i=1;i<=num/2;i++){
        if(s[i]!=s[num-i+1]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
