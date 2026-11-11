#include<iostream>
#include<cstdio>
using namespace std;
long long n,a,cnt;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>a>>c;
        while(a--)s=s+c;
    }
    int len=s.size();
    s=" "+s;
    for(int i=1;i<=len/2;i++){
        if(s[i]!=s[n-i+1])cnt++;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
