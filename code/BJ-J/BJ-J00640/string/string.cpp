#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
struct node{
    int a;
    char c;
}x[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i].a>>x[i].c;
    int l=1,r=n;
    while(l<r){
        if(x[l].c!=x[r].c){
            if(x[l].a==x[r].a){
                ans+=x[l].a;
                l++,r--;
            }
            else if(x[l].a>x[r].a){
                ans+=x[r].a; 
                x[l].a-=x[r].a;
                r--;
            }
            else{
                ans+=x[l].a;
                x[r].a-=x[l].a;
                l++;
            }
        }
        else{
            if(x[l].a==x[r].a)l++,r--;
            else if(x[l].a>x[r].a){
                x[l].a-=x[r].a;
                r--;
            }
            else{
                x[r].a-=x[l].a;
                l++;
            }            
        }
        
    }
    cout<<ans<<endl;
    return 0;
}