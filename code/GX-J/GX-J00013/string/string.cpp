#include<bits/stdc++.h>
using namespace std;

struct N{
    int num;
    char c;
}a[200002]={};
char s[5000000]={};

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,sum=0,p=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].num>>a[i].c;
        for(int i=p;i<a[i].num;i++){
            s[p]=a[i].c;
            ++p;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]!=s[p-1-i]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
