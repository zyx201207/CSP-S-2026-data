#include<bits/stdc++.h>
using namespace std;
struct node{
    long long a;
    char s;
}m[1000009];
long long q;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>m[i].a>>m[i].s;
    }
    long long ans=0;
    long long l=1,r=q;
    while(l<r){
        if(m[l].s==m[r].s){
            if(m[l].a>m[r].a){
                m[l].a-=m[r].a;
                r--;
            }
            else if(m[l].a==m[r].a){
                l++;
                r--;
            }
            else{
                m[r].a-=m[l].a;
                l++;
            }
        }
        else {
            if(m[l].a>m[r].a){
                ans+=m[r].a;
                m[l].a-=m[r].a;
                r--;
            }
            else if(m[l].a==m[r].a){
                    ans+=m[l].a;
                l++;
                r--;
            }
            else{
                    ans+=m[l].a;
                m[r].a-=m[l].a;
            l++;
            }
        }
    }

    cout<<ans;
    return 0;
}
