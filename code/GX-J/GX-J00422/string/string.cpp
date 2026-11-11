#include<bits/stdc++.h>
using namespace std;
long long n,x=0,y=0;
long long a;
char s[10005],b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        cin>>b;
        for(long long j=y;j<y+a;j++){
            s[j]=b;
        }
        y+=a;
    }
    int v=strlen(s);
    if(v%2==0){
        int p=v/2;
        int q=v/2+1;
        for(long long i=1;i<=p-1;i++){
            if(s[q+i]!=s[p-i]) x++;
        }
    }
    if(v%2!=0){
        int p=v/2;
        for(long long i=1;i<=p;i++){
            if(s[p+i]!=s[p-i]) x++;
        }
    }
    cout<<x;
    return 0;
}
