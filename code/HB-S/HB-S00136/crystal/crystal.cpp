#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int start=i;
        int flag=0;
        for(int j=start;j>=1;j--){
            if(flag) break;
            flag=0;
            int cnt=0;
			int num=1;
			int s[500005];
            for(int i=1;i<=n;i++){
                s[i]=a[i];
            }
            for(int k=start;k<=n;k++){
                if(cnt+s[start]-s[j]<=m){
                    if(j!=start){
                        cnt+=s[start]-s[j];
                        num++;
                    }
                }else{
                    flag=1;
                }
                if(cnt+num*(s[k]-s[start])<=m){
                    if(k!=start){
                        cnt+=num*(s[k]-s[start]);
                        s[start]=s[k];
                        num++;
                    }
                }else{
                    ans=max(ans,num);
                    break;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
