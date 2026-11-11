#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
    int len;
    char c;
}a[N];
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    int l=1,r=0,L=1,R=n;
    for(int i=1;i<=n;i++){
        cin>>a[i].len>>a[i].c;
        r+=a[i].len;
    }
//    cout<<l<<'~'<<r<<'\n';
    long long cnt=0;
    while(L<R){
        int mi=min(a[L].len,a[R].len);
        if(a[L].c!=a[R].c){
            cnt+=mi;
        }
        a[L].len-=mi;
        a[R].len-=mi;
        if(a[L].len==0) L++;
        else R--;
    }
    cout<<cnt;
    return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
