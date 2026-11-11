#include<bits/stdc++.h>
using namespace std;
string s;
int n;
long long int res=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=0;j<a;j++){
            s+=c;
        }
    }
    int len=(int)s.size();
    int mid=len/2;
    if(len%2==0) mid--;
     for(int i=0,j=len-1;i<=mid;i++,j--){
        if(s[i]!=s[j]) res++;
     }
     cout<<res<<'\n';
     return 0;
}