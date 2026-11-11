#include<bits/stdc++.h>
using namespace std;
struct str{
    long long a;
    char c;
}a[200100];
int n;
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].c;
    }
    for(int l=1,r=n;l<r;){
        if(a[l].a==a[r].a){
            if(a[l].c==a[r].c){
                l++,r--;
            }else{
                ans+=a[l].a;
                l++,r--;
            }
        }else{
            if(a[l].c==a[r].c){
                if(a[l].a<a[r].a){
                    a[r].a-=a[l].a;
                    l++;
                }else{
                    a[l].a-=a[r].a;
                    r--;
                }
            }else{
                if(a[l].a<a[r].a){
                    ans+=a[l].a;
                    a[r].a-=a[l].a;
                    l++;
                }else{
                    ans+=a[r].a;
                    a[l].a-=a[r].a;
                    r--;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
