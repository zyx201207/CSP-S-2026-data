#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[200005];
    long long ans=0;
    char c[200005];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    long long li=a[1],ri=a[n];
    while(l<r){
        if(c[l]!=c[r]){
            if(li!=ri){
                if(li>ri){
                    ans+=ri;
                    li-=ri;
                    r--;
                    ri=a[r];
                }else{
                    ans+=li;
                    ri-=li;
                    l++;
                    li=a[l];
                }
            }else{
                ans+=ri;
                l++;
                r--;
                li=a[l];
                ri=a[r];
            }
        }else{
            if(li!=ri){
                if(li>ri){
                    li-=ri;
                    r--;
                    ri=a[r];
                }else{
                    ri-=li;
                    l++;
                    li=a[l];
                }
            }else{
                l++;
                r--;
                li=a[l];
                ri=a[r];
            }
        }
    }
    cout<<ans;
	return 0;
}
