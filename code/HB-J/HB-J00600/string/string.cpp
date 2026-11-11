#include<bits/stdc++.h>
using namespace std;
int n;
int m,h;
char a;
int c[10000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    h=1;
    for(int i=1; i<=n; i++){
        cin>>m>>a;
        for(int j=h; i>=h+m;j++ ){
            c[j]=a;
        }
        h+=m;

    }
    int cnt=0;

    for(int i=1; i<=n; i++){
        if(c[i]!=c[i-1]){
           cnt++;


        }

    }

    cout<<cnt;





    return 0;
}
