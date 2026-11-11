#include<bits/stdc++.h>
using namespace std;
string s,s1;
int n,m;
char c,c1;
long long len,sum;
int main(){
    freopen("string.in",'r',stdin);
    freopen("string.out",'w',stdout);
    cin>>n;
    while(n--){
        cin>>m>>c;
        for(int i=1;i<=m;i++)s+=c;
    }
    len=s.size();
    for(long long i=0;i<=len/2+1;i++){
        if(s[i]!=s[len-1-i])sum++;
    }
    cout<<sum;
    return 0;
}
