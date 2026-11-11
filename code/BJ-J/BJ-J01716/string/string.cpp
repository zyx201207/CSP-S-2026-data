#include<bits/stdc++.h>
using namespace std;
struct node{
    int num;
    char c;
}a[200006];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long cnt=-1;
    for(int i=0;i<n;i++){
        cin>>a[i].num>>a[i].c;
        cnt+=a[i].num;
    }
    long long l=0,r=n-1,ans=0;
    while(r>l){
        if(a[l].c!=a[r].c){
            ans+=min(a[l].num,a[r].num);
        }
        if(a[l].num>a[r].num){
            a[l].num-=a[r].num;
            r--;
        }
        else if(a[l].num>a[r].num){
            a[r].num-=a[l].num;
            l++;
        }
        else{
            l++;
            r--;
        }
    }
    cout<<ans;
}
