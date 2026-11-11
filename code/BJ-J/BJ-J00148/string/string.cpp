#include<iostream>
#include<cstdio>
using namespace std;
int n;
struct node
{
    int number;
    char c;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].number>>a[i].c;
    int l=1,r=n;
    long long ans=0;
    while(l<r){
        int mn=min(a[l].number,a[r].number);
        if(a[l].c==a[r].c){
            a[l].number-=mn;
            a[r].number-=mn;
            if(a[l].number==0)l++;
            if(a[r].number==0)r--;
        }
        else{
            ans+=mn;
            a[l].number-=mn;
            a[r].number-=mn;
            if(a[l].number==0)l++;
            if(a[r].number==0)r--;
        }
    }
    cout<<ans;
    return 0;
}
