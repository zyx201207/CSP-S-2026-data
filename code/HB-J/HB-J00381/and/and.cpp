#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define LL long long
int n,m,ans,idx;
int nums[N];
bool book[N];
void dfs(int now,int cho){
    //cout<<now<<" "<<cho<<endl;
    if(cho>=m){
        int x=-1;
        for(int i=1;i<=n;i++){
            if(book[i]){
                //cout<<nums[i]<<" ";
                if(x==-1){
                    x=nums[i];
                }else{
                    x=x&nums[i];
                }
            }
        }
        //cout<<endl<<x<<endl;
        ans=max(ans,x);
        return;
    }
    if(now>n)return;
    book[now]=1;
    dfs(now+1,cho+1);
    book[now]=0;
    dfs(now+1,cho);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }
    if(n<=20||m==1||m==2)dfs(1,0);
    else{
        if(m==n-1){
            int x;
            for(int i=1;i<=n;i++){
                if(i==1)x=nums[i];
                else x=x&nums[i];
            }
            for(int i=1;i<=n;i++){
                ans=max(ans,x^nums[i]);
            }
        }else if(m==n){
            int x;
            for(int i=1;i<=n;i++){
                if(i==1)x=nums[i];
                else x=x&nums[i];
            }
            ans=x;
        }else{
            sort(nums+1,nums+n+1,greater<int>());
            for(int i=1;i+m-1<=n;i++){
                int x;
                for(int j=i;j<=i+m-1;j++){
                    if(j==i)x=nums[j];
                    else x=x&nums[j];
                }
                ans=max(ans,x);
            }
        }
    }
    cout<<ans;
    return 0;
}
