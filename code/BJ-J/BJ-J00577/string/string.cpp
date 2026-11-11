#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,l,r,mid;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        ll a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    //cout<<s<<" ";
    ll siz=s.size(),cnt=0;
    if(siz%2==1){
        ll mid=(1+siz)/2-1;
        ll l=r=mid;
        while(true){
            if(s[l]!=s[r]){
                cnt++;
                if(l-1==-1 || r+1==siz){
                    break;
                }else{
                    l-=1;
                    r+=1;
                }
            }else{
                if(l-1==-1 || r+1==siz){
                    break;
                }else{
                    l-=1;
                    r+=1;
                }
            }
        }
    }else{
        ll mid=siz/2;
        ll l=mid/2-1,r=mid;
        while(true){
            if(s[l]!=s[r]){
                cnt++;
                if(l-1==-1 || r+1==siz){
                    break;
                }else{
                    l--;
                    r++;
                }
            }
            else{
                if(l-1==-1 || r+1==siz){
                    break;
                }else{
                    l-=1;
                    r+=1;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
