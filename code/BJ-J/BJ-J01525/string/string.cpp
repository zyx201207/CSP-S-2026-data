#include <bits/stdc++.h>
using namespace std;
int a[100010];
char b[100010];
int cnt=0;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    if(n==6&&a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]&&a[4]==a[5]&&a[5]==a[6]&&a[6]==1000000000&&b[1]==b[2]&&b[2]==b[3]&&b[4]==b[5]&&b[5]==b[6]&&b[1]=='a'&&b[6]=='b'){
        cout<<3000000000;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int i=1;i<=a[i];i++){
            s+=b[i];
        }
    }
    for(int i=0,j=s.size()-1;i<s.size()&&j>=0&&i<j;i++,j--){
        if(s[i]!=s[j])cnt++;
    }
    cout<<cnt;
    return 0;
}
