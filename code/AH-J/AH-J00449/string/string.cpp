#include<iostream>
using namespace std;
long long  cnt,a,b[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>a;
    for(int n=1;n<=a;n++){
        cin>>b[n]>>c[n];
    }
    long long l=1,r=a;
    while(l<r){
        if(c[l]!=c[r]){
            cnt+=min(b[l],b[r]);
        }
        if(b[l]==b[r]){
            l++;
            r--;
        }
        else if(b[l]>b[r]){
            b[l]-=b[r];
            r--;
        }
        else{
            b[r]-=b[l];
            l++;
        }
    }
    cout<<cnt;
    return 0;
}
