#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,cnt;
ll ans,a[200010];
char s[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>cnt;
    while(cnt--){
        ll l;char c;
        cin>>l>>c;
        if(c==s[n])
            a[n]+=l;
        else{
            a[++n]=l;
            s[n]=c;
        }
    }
    for(int i=1,j=n;i<j;){
        if(a[i]>a[j]){
            while(1){
                if(s[i]!=s[j]){
                    if(a[i]>a[j]){
                        ans+=a[j];
                        a[i]-=a[j];
                        j--;
                        if(i>=j){
                            cout<<ans;
                            return 0;
                        }
                    }else{
                        ans+=a[i];
                        a[j]-=a[i];
                        i++;
                        break;
                    }
                }else{
                    if(a[i]<a[j]){
                        a[j]-=a[i];
                        i++;
                        break;
                    }else{
                        a[i]-=a[j];
                        j--;
                        if(i>=j){
                            cout<<ans;
                            return 0;
                        }
                    }
                }
            }
        }else{
            while(1){
                if(s[i]!=s[j]){
                    if(a[j]>a[i]){
                        ans+=a[i];
                        a[j]-=a[i];
                        i++;
                        if(i>=j){
                            cout<<ans;
                            return 0;
                        }
                    }else{
                        ans+=a[j];
                        a[i]-=a[j];
                        j--;
                        break;
                    }
                }else{
                    if(a[j]<a[i]){
                        a[i]-=a[j];
                        j--;
                        break;
                    }else{
                        a[j]-=a[i];
                        i++;
                        if(i>=j){
                            cout<<ans;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
//freopen("string.in","r",stdin);
//freopen("string.out","w",stdout);
