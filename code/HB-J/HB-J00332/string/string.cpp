#include<bits/stdc++.h>
using namespace std;
long long n,a,cnt,m;
char c,s[1000000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a;
        cin>>c;
        for(long long j=cnt;j<cnt+a;j++){
            s[j]=c;
        }
        cnt+=a;
    }
    if(cnt%2==0){
        for(long long i=0;i<cnt/2;i++){
            if(s[cnt/2-i-1]==s[cnt/2+i]) m+=0;
            else m++;
        }
    }
    else{
        for(long long i=0;i<cnt/2;i++){
            if(s[cnt/2-i-1]==s[cnt/2+i+1]) m+=0;
            else m++;
        }
    }
    cout<<m;
    return 0;
}
