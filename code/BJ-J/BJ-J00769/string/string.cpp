#include <iostream>
using namespace std;
const int maxn=200010;
int a[maxn];
char c[maxn];
int n;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int len=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        len+=a[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    int cnt=0;
    int p1=len-1,p2=0;
    while(p1>p2){
        if(s[p1]!=s[p2]){
            cnt++;
        }
        p1--;
        p2++;
    }
    cout<<cnt;
    return 0;
}

