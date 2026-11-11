#include<bits/stdc++.h>
using namespace std;
long long a[200010];
long long s;
char c[200010];
string ss;
long long cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    ss+='0';
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        s+=a[i];
        for(int j=1;j<=a[i];j++){
            ss+=c[i];
        }
    }
    if(s%2==0){
        s=s/2;
        if(ss[s+1]!=ss[s]){
            cnt++;
        }
        for(long long i=1;i<=s-1;i++){
            if(ss[s+i+1]!=ss[s-i]){
                cnt++;
            }
        }
        cout<<cnt;
    }else{
        s=s/2+1;
        for(long long i=1;i<=s-1;i++){
            if(ss[s+i]!=ss[s-i]){
                cnt++;
            }
        }
        cout<<cnt;
    }
    return 0;
}

