#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char c[200100];
int sum;
int cnt;
char s[1000000010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=sum+1;j<=sum+a[i];j++){
            s[j]=c[i];
        }
        sum+=a[i];
    }
    if(sum%2){
        for(int i=(sum+2)/2+1;i<=sum;i++){
            if(s[i]!=s[(sum+2)/2+1-(i-(sum+2)/2+1)])cnt++;
        }
    }else{
        for(int i=(sum+2)/2;i<=sum;i++){
            if(s[i]!=s[(sum+2)/2-(i-(sum+2)/2+1)])cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
