#include<bits/stdc++.h>
using namespace std;
struct what{
    char c;
    int ak;
    long long qzh;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long sum=0;
    string ddd;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].ak>>a[i].c;
        for(int j=1;j<=a[i].ak;j++){
            ddd+=a[i].c;
        }
    }
    int len=ceil(ddd.size()/2);
    int cnt=0;
    for(int i=len;i<ddd.size();i++){
        if(ddd[i]!=ddd[ddd.size()-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
