#include<bits/stdc++.h>
using namespace std;
const int maxn=2002;
char a[maxn];
int b[maxn],cnt;
string s0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i]>>a[i];
        for(int j=1;j<=b[i];j++){
            s0+=a[i];
        }
    }
    int len=s0.size();
    //cout<<len<<endl;
    for(int i=0;i<len/2;i++){
        if(s0[i]!=s0[len-1-i]){
            //cout<<"#1 "<<i<<" "<<len-1-i<<" "<<s0[i]<<" "<<s0[len-1-i]<<endl;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
