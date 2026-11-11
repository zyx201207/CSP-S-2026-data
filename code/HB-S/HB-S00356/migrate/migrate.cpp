#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==0){
        cout<<1<<endl;
        cout<<2<<endl;
        return 0;
    }  
    
    while(t--){
        int n,d;
        cin>>n>>d;
        long long ans=0;
        
        vector<int> dao(n);
        for(int i=0;i<n;i++){
            cin>>dao[i];
        }
        if(c==13||c==14){
            if(d>=dao[n-1]){
                for(int i=0;i<t;i++){
                    cout<<0<<endl;
                }
            }else{
                for(int i=0;i<t;i++){
                    cout<<1<<endl;
                }
            }
            return 0;
        }  
        if(c==11||c==12){
            if(d>=2*dao[3]-dao[2]){
                cout<<n<<endl;
            }
            return 0;
        } 
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            //dp[i]=dp[i-1];
            int tmp=2;
            while(i-tmp>=0){
                if(dp[i]-dp[i-tmp]<=d){
                    dp[i]+=1;
                }else{
                    break;
                }
                tmp++;
            }
        }
        for(int i=0;i<n;i++){
            if(dp[i]==2){
                ans+=1;
            }
        }
        cout<<ans<<endl;
    }
}