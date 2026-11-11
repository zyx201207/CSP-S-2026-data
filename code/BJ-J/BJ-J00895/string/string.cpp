#include <iostream>
using namespace std;
int n;
int a[200005],c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long cnt=0;
    for(int i=1; i<=n; i++){
        char tc;
        cin>>a[i]>>tc;
        c[i]=(int)tc;
        cnt+=a[i];
    }
    int c=0;
    for(long long i=1; i<=cnt/2; i++){
        long long ii=i;
        long long j=cnt-i+1;
        int c1=0,c2=0;
        while(ii>0){
            c1++;
            ii-=a[c1];
        }
        while(j>0){
            c2++;
            j-=a[c2];
        }
        c++;
    }
    cout<<c;
    return 0;
}
