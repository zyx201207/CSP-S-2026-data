#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
struct Node{
    int x;
    char c;
};
int n;
int a[N];
char b[N];
int A[N];
char B[N];
stack <Node> st1;
stack <Node> st2;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    int l=1,r=n;
    int ans=0;
    while(l<=r){
        if(st1.empty()){
            st1.push({a[l],b[l]});
            l++;
        }
        if(l<=r and st2.empty()){
            st2.push({a[r],b[r]});
            r--;
        }
        while(!st1.empty() and !st2.empty()){
            int x1=st1.top().x,x2=st2.top().x;
            char c1=st1.top().c,c2=st2.top().c;
            st1.pop();
            st2.pop();
            int sum=0;
            if(x1==x2){
                sum=x1;
            }
            if(x1>x2){
                sum=x2;
                st1.push({x1-x2,c1});
            }
            if(x2>x1){
                sum=x1;
                st2.push({x2-x1,c2});
            }
            if(c1!=c2){
                ans+=sum;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
