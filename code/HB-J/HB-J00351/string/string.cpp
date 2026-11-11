#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
long long ans;
struct node{
    long long num;
    char ch;
}a[N],k[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k[i].num>>k[i].ch;
    }
    int m=1;a[1].num=k[1].num;a[1].ch=k[1].ch;
    for(int i=2;i<=n;i++){
        if(k[i].ch==k[i-1].ch){
            a[m].num+=k[i].num;
        }else{
            a[++m].ch=k[i].ch;
            a[m].num=k[i].num;
        }
    }
    int l=1,r=m;
    while(l<r){
        if(a[l].ch==a[r].ch){
            if(a[l].num==a[r].num){
                l++;
                r--;
            }else if(a[l].num>a[r].num){
                a[l].num-=a[r].num;
                r--;
            }else{
                a[r].num-=a[l].num;
                l++;
            }
        }else{
            ans+=min(a[l].num,a[r].num);
            if(a[l].num==a[r].num){
                l++;
                r--;
            }else if(a[l].num>a[r].num){
                a[l].num-=a[r].num;
                r--;
            }else {
                a[r].num-=a[l].num;
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}
