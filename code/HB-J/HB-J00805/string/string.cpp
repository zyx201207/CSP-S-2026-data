#include<bits/stdc++.h>
using namespace std;
struct S{
    long long leng;
    char duan;                 
}s[100000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,shu=0,num=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i].leng >> s[i].duan;
        shu+=s[i].leng;
    }
    int ci=0,fanci=n-1;
    for(long long i=0;i<shu/2;i++){
        if(s[ci].duan!=s[fanci].duan){
            num+=min(s[ci].leng,s[fanci].leng);
            i+=min(s[ci].leng,s[fanci].leng);
            if(s[ci].leng<s[fanci].leng)ci++;
            else if(s[ci].leng>s[fanci].leng)fanci--;
            else ci++;fanci--;
        }
        else{
            i+=min(s[ci].leng,s[fanci].leng);
            if(s[ci].leng<s[fanci].leng)ci++;
            else if(s[ci].leng>s[fanci].leng)fanci--;
            else ci++;fanci--;
        }
    }
    cout <<  num<<endl;
    return 0;
}