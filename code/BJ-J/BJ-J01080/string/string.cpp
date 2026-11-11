#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
char ch1[700000005],ch2[700000005],ch[700000005];
long long j=0;
void v(int a,int c){
    for(int k=1;k<=a;k++){
        j++;
        ch1[j]=c;
    }
}
void v2(int a,int c){
    for(int k=1;k<=a;k++){
        j++;
        ch[j]=c;
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long n1=n/2;
    long long n2=n-n1;

    for(long long i=1;i<=n1;i++){
        long long a;
        char c;
        cin>>a>>c;
        v(a,c);
    }
    long long sum=j;
    j=0;
    for(long long i=1;i<=n2;i++){
        long long a;
        char c;
        cin>>a>>c;
        v2(a,c);
    }
    for(int i=1;i<=n2;i++){
        ch2[i]=ch[n2-i+1];
    }
    long long cnt=0;
    for(long long i=1;i<=n2;i++){
            /**/
        if(ch2[i]!=ch1[i]){
            cnt++;
        }


        //cout<<ch2[i];
    }
    cout<<cnt;
    return 0;
}
