#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    string s;
    long long n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        char k;
        cin>>k;
        for(int j=1;j<=a;j++)
            s+=k;
    }
    long long len=s.length();
    for(int i=0;i<len/2;i++)
        if(s[i]!=s[len-i-1]) cnt++;
    cout<<cnt;
    return 0;
}