#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
struct str{
    int node;
    char c;
}a[N];
long long sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].node>>a[i].c;
    }
    int i=1,j=n;
    while(i<j){
        if(a[i].node==0) i++;
        if(a[j].node==0) j--;
        if(a[i].c==a[j].c){
            if(a[i].node>a[j].node){
                    a[i].node=a[i].node-a[j].node;
                    a[j].node=0;
            }
            else {
                a[j].node=a[j].node-a[i].node;
                a[i].node=0;
            }
        }
        else if(a[i].c!=a[j].c){
            sum+=min(a[i].node,a[j].node);
            if(a[i].node>a[j].node){
                    a[i].node=a[i].node-a[j].node;
                    a[j].node=0;
            }
            else {
                a[j].node=a[j].node-a[i].node;
                a[i].node=0;
            }
        }
    }
    cout<<sum;
    return 0;
}
