#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,l=1,r,li,ri,ans,st[200001],ed[200001],a[200001];
char s[200001];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){
		cout<<0;
		return 0;
	}
    ed[0]=-1;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>s[i];
        st[i]=ed[i-1]+1;
        ed[i]=st[i]+a[i]-1;
    }
    r=n;
    ri=ed[n];
    while(1){
		if(li>ri){
			break;
		}
        if(ed[n]-li<ri){//yi r
            if(ed[n]-li<ed[r-1]){
                if(s[l-1]!=s[r]){
                    ans+=(ri-ed[r-1]);
                }
                ri=ed[--r];
            }
            else{
                if(s[l-1]!=s[r]){
                    ans+=(ri-(ed[n]-li));
                }
                ri=ed[n]-li;
            }
        }
        else if(ed[n]-li>ri){
            if(ed[n]-li>st[l+1]){
                if(s[l]!=s[r+1]){
                    ans+=(st[l+1]-li);
                }
                li=st[++l];
            }
            else{
                if(s[l]!=s[r+1]){
                    ans+=((ed[n]-ri)-li);
                }
                li=ed[n]-ri;
            }
        }
        else{
            if((ri==(ed[n]+1)/2&&ed[n]%2==1)||(ed[n]%2==0&&ri==ed[n]/2+1)){
                break;
            }
            li=st[++l];
        }
    }
    cout<<ans;
    return 0;
}
