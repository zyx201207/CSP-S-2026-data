#include<bits/stdc++.h>
using namespace std;
const int LENGTH=2e5+5;
int a[LENGTH]={0};
char b[LENGTH]={'0'};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    long long i=1,j=n;
    while(i<j){
        if(b[i]==b[j]){
            int x=min(a[i],a[j]);
            a[i]-=x;
            a[j]-=x;
            if(a[i]==0) i++;
            else j--;
        }
        else{
            int x=min(a[i],a[j]);
            a[i]-=x;
            a[j]-=x;
            cnt+=x;
            if(a[i]==0) i++;
            else j--;
        }
    }
    cout<<cnt;
    return 0;
}
