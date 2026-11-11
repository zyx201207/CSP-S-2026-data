#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node{
    int n;
    char c;
}a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
        cin>>a[i].n>>a[i].c;
    long long ans=0;
    for(int i=1,j=t;i<j;i++){
        do{
            int num=min(a[i].n,a[j].n);
            if(a[i].c!=a[j].c)
                ans+=num;
            a[i].n-=num;
            a[j].n-=num;
            if(a[j].n)
                break;
            j--;
        }while(i<j);
    }
    cout<<ans;
    return 0;
}
