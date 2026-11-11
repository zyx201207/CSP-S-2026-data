#include<bits/stdc++.h>
using namespace std;
long long n;
struct student{
    long long b;
    char c;
}a[300001];
long long a1[300001];
unsigned long long len;
unsigned long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].b>>a[i].c;
    }
    for(int i=1;i<=n;i++){
        len+=a[i].b;
        a1[i]=a1[i-1]+a[i].b;
    }
    if(len>=2000000000){
        cout<<len/2;
        return 0;
    }
    int sum=1;
    int sumn=len;
    for(int i=1;i<=len/2;i++){
        int x=0,y=0;
        for(int j=1;j<=n;j++){
            if(sum<=a1[j] && sum>a1[j-1]){
                x=j;
                break;
            }
        }
        for(int j=n;j>=1;j--){
            if(sumn<=a1[j] && sumn>a1[j-1]){
                y=j;
                break;
            }
        }
        if(a[x].c!=a[y].c)ans++;
        sum++,sumn--;
    }
    cout<<ans;
    return 0;
}
