
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,_a[N];char _c[N];
int sum;
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n;
    s+=" ";
    for(int i = 1;i <= n;i++){
        cin >> _a[i] >> _c[i];
        for(int j = 1;j <= _a[i];j++){
            s+=_c[i];
        }
        sum+=_a[i];
    }
    int pos=(sum+1)>>1;
    int cnt=0;
    if(sum%2==1){
        for(int delta=1;delta < pos;delta++){
            if(s[pos+delta]!=s[pos-delta])cnt++;
        }
        cout << cnt<< endl;
    }
    else{
        int l=pos,r=pos+1;
        for(int delta=0;delta < pos;delta++){
            if(s[l-delta]!=s[r+delta])cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
