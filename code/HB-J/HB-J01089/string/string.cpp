#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
struct Node{
    long long num;
    char c;
}a[N];
int n;
long long sum,suml,sumr;
int l,r;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    r=n-1;
    for(int i=0;i<n;i++){
        cin>>a[i].num>>a[i].c;
    }
    for(l=0;l<=r;l++){
        suml+=a[l].num;
        for(;r>=l&&suml!=sumr;){
            if(a[l].c!=a[r].c){
                if(suml<=a[r].num+sumr){
                    ans=ans+suml-sumr;
                    a[r].num=a[r].num-suml+sumr;
                    sumr=suml;
                }
                else{
                    ans=ans+a[r].num;
                    sumr=sumr+a[r].num;
                    r--;
                }
            }
            else{
                if(suml<=a[r].num+sumr){
                    a[r].num-=suml-sumr;
                    sumr=suml;
                }
                else{
                    sumr+=a[r].num;
                    r--;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
