#include<bits/stdc++.h>
using namespace std;
char s[2000005];
long long s1[2000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long x;
    cin>>x;
    for(long long i=1;i<=x;i++){
        long long a;
        char b;
        cin>>a>>b;
        s1[i]=a;
        s[i]=b;
    }
    long long cnt1=0;
    long long i=1,j=x;
    for(;i<=j;){
        int flag;
        if(s[i]==s[j]){
            flag=0;
        }else{
            flag=1;
        }
        if(s1[i]<=s1[j]){
            cnt1+=flag*s1[i];
            s1[j]-=s1[i];
            i++;
        }else{
            cnt1+=flag*s1[j];
            s1[i]-=s1[j];
            j--;
        }
    }
    cout<<cnt1;
    return 0;
}
