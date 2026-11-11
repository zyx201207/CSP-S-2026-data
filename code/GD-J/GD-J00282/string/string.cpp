#include<bits/stdc++.h>
using namespace std;
struct d{
    int c;
    char a;
} lis[200005];
char ls[1000000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>lis[i].c>>lis[i].a;
    }
    int k=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=lis[i].c;j++){
            k++;
            ls[k]=lis[i].a;
        }
    }
    if(k%2==0){
        long long s=k/2+1,l=1,b=0;
        for(int i=s;i<=k;i++){
            if(ls[i]!=ls[i-l]) b++;
            l+=2;
        }
        cout<<b;
    }
    else{
        long long s=k/2+2,l=2,b=0;
        for(int i=s;i<=k;i++){
            if(ls[i]!=ls[i-l]){
                b++;
            }
            l+=2;
        }
        cout<<b;
    }
    return 0;
}
