#include <iostream>
#include <string.h>
using namespace std;
const int MAXN=200005;
const int MAXM=1000000000;
int a[MAXN];
char c[MAXN];
char s[MAXM];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int N;
    long long len=0,cnt=0,k=0;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>a[i];
        cin>>c[i];
        len+=a[i];
        for(int j=0;j<a[i];j++){
            s[k++]=c[i];
        }
    }
    for(int i=0;i<len;i++){
        if(s[i]!=s[len-1-i]){
            cnt++;
        }
    }
    cout<<cnt/2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
