#include<bits/stdc++.h>
using namespace std;
long long n,len=0,k,t=0,sum=0,p;
char c;
string s={},a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>p;
    for(int i=0;i<p;i++){
        cin>>n>>c;
        while(n--){
            s[len]=c;
            len++;
        }
    }
    long long mid=len/2-1;
    if(len%2==0){
        k=mid+1;
    }else{
        k=mid+2;
    }
    for(int i=0;i<=mid;i++){
        a[t]=s[i];
        t++;
    }
    for(int i=k;i<len;i++){
        if(s[i]!=a[t-1]){
            sum++;
        }
        t--;
    }
    cout<<sum;
    return 0;
}
