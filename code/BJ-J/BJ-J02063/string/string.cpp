#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
string s;
long long l;
int cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        l+=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    string d=s;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(d[i]!=s[i]){
            cnt++;
        }
    }
    cnt=cnt/2;
    cout<<cnt;
    return 0;
}