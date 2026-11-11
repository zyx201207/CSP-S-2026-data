#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,sum,half,cnt;
struct node{
    int a;
    string c;
}a[N];
string s1,s2,s;
void check(string s){
    for(int i=0;i<half;i++){
        s1+=s[i];
    }
    for(int i=sum-1;i>=sum-half;i--){
        s2+=s[i];
    }
    if(s1==s2){
        cout<<0;
    }
    else{
        for(int i=0;i<half;i++){
            if(s1[i]!=s2[i]){
                cnt++;
            }
        }
        cout<<cnt;
    }
    //cout<<s1<<" "<<s2;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].c;
        sum+=a[i].a;
        for(int j=0;j<a[i].a;j++){
            s+=a[i].c;
        }
    }
    half=sum/2;
    check(s);
    return 0;
}
