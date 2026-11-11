#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
    int x;
    int num;
}a[N];
int n,m;
bool cmp(node a,node b){
    if(a.num==b.num) return a.x>b.x;
    return a.num>b.num;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
        int temp=a[i].x;
        while(temp){
            if(temp%2==1) a[i].num++;
            temp/=2;
        }
    }
    sort(a+1,a+n+1,cmp);
    int ans=a[1].x;
    for(int i=1;i<=m;i++){
        cout<<a[i].x<<' ';
        ans&=a[i].x;
    }
    cout<<ans;
}
