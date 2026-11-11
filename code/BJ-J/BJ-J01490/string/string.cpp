#include<iostream>
#include<cstdio>
using namespace std;
const int N = 2e5+10;
struct subs{
    long long l;
    char c;
} s[N];
int n;
unsigned int cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    char c;
    for(long long i= 1,a;i<=n;i++){
        cin >> a >> c;
        s[i]={a,c};
    }
    int l=1,r=n;
    while(l<r){
        if(s[l].l<=s[r].l){
            s[r].l-=s[l].l;
           if(s[l].c != s[r].c) cnt+=s[l].l;
            if(s[r].l==0) r--;
            l++;
        }else{
           if(s[l].c != s[r].c) cnt+=s[r].l;
            s[l].l-=s[r].l;
            r--;
        }
    }
    cout<<cnt;
    return 0;
}