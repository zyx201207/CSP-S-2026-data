#include<bits/stdc++.h>
using namespace std;
int x[200005];
bool flag[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,cnt=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        flag[i]=true;
    }
    for(int i=29;i>=0;i--){
        int c=0;
        for(int j=1;j<=n;j++){
            if(flag[j]&&((x[j]>>i)&1)){
                c++;
            }
        }
        if(c>=k){
            cnt+=(1<<i);
            for(int j=1;j<=n;j++){
                if(flag[j]&&(((x[j]>>i)&1)==0)){
                    flag[j]=false;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
