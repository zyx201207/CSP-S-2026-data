#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    int mi=100000010;
    int a[200010];
    char c[200010];
    cin>>n;
    int m=n;

    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int t=1;
while(m--){
        int sum=0;
        string s;
        for(int i=t;i<=n+t;i++){
            for(int j=1;j<=a[i];j++){
                s+=c[i];
            }
        }
        for(int i=0;i<=s.size()/2;i++){
            if(s[i]!=s[s.size()-1-i]) sum++;
        }
        if(sum<mi) mi=sum;
        t++;
        a[t+n]=a[t-1];
        c[t+n]=c[t-1];
    }
    cout<<mi;

return 0;
}
