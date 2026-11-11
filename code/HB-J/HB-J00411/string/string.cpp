#include<bits/stdc++.h>
using namespace std;
long long n;
long long r;
string s;
long long a[100005];
char b[100005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n;i++){
        char bb;
        long long aa;
        aa=a[i];
        bb=b[i];
        while(aa--){
            s+=bb;
        }
        aa=0;
        bb=' ';
    }
    long long lon;
    lon=s.size();
    for(int i=0;i<lon/2;i++){
        if(s[i]!=s[lon-i-1]) r++;
    }
    cout<<r;
    return 0;
}
