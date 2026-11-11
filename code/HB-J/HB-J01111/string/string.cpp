#include<iostream>
using namespace std;
typedef long long ll;
const int N=2e5+7;
int n,x;ll cnt;char c;string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>x>>c;
        while(x--)s+=c;
    }
    for(int i=0,j=s.length()-1;i<=j;i++,j--){
        if(s[i]!=s[j])cnt++;
    }
    cout<<cnt;
    return 0;
}
