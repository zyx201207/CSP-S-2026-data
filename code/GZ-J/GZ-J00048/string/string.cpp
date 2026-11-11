//GZ-J00048  赵晨希   贵阳市白云区第十四中学
#include<bits/stdc++.h>
using namespace std;
long long a[100000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s,c;
    int n,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=0;i<n;i++){
        for(int l=1;l<=a[i];l++)
        s=s+c[i];
    }
    for(int i=0;i<n;i++){
        if (s[i]!=s[n+1-i]) {
            s[i]=s[n+1-i];
            cnt+=1;
            }
        }
    cout<<cnt;

    return 0;
}
