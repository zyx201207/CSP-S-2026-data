#include<bits/stdc++.h>
using namespace std;
bool check(string x){
    long long l=0,r=x.size()-1;
    while(l<=r){
        if(x[l]!=x[r]) return 0;
        l++;
        r--;
    }
    return 1;
}
string fix(string x){
    long long l=0,r=x.size()-1;
    while(l<=r){
        if(x[l]!=x[r]){
            x[l]=x[r];
            return x;
        }
        l++;
        r--;
    }
    return x;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    long long n,cnt=0,a[200005];
    cin>>n;
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        char c;
        cin>>c;
        for(long long j=1;j<=a[i];j++) s=c+s;
    }
    while(!check(s)){
        s=fix(s);
        cnt++;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
