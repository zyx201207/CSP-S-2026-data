#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
//int ;
long long x[maxn],dp[maxn],dpp[maxn],ans,c,t,n,d;
void init(int j,int n){
    dp [j]=1;
    dpp[j]=0;
    for(int i=j+1;i<=n;i++){
        dp [i]=0;
        dpp[i]=1e18+7;
    }
    //cout<<"init complete!now is time for "<<j<<endl;
}
int main(){
    freopen ("migrate.in","r",stdin);
    freopen ("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        ans=0;
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[j];
            //cout<<"x"<<i<<"="<<x[j]<<"\n";
        }
        for(int j=1;j<=n;j++){                          //FROM_WHICH_ILAND
            init(j,n);
            queue<int> q;
            q.push(j);
            while(!q.empty()){
                int j=q.front();
                //cout<<"from "<<j<<",have walked "<<dpp[j]<<" steps\n\n";
                for(int k=j+1;(((x[k]-x[j])<=d)&&(k<=n));k++){     //TO_WHICH_ILAND
                    //cout<<"    to "<<k<<endl;
                    if (dpp[k]>dpp[j]+1){               //IT_ISN'T_THE_SHORTEST_ONE
                        dpp[k]=dpp[j]+1;
                        dp [k]=dp [j];
                        //cout<<"        a shorter way "<<dpp[k]<<","<<dp[k]<<" ways\n";
                        q.push(k);
                    }else if(dpp[k]==dpp[j]+1){                         //MORE_WAYS
                        dp[k]+=dp[j];
                        //cout<<"        find more ways to "<<k<<",num="<<dp[k]<<endl;
                        q.push(k);
                    }
                    //cout<<endl;
                }
                q.pop();
            }
            for(int k=j+1;k<=n;k++){
                if(dp[k]==2){
                    //cout<<"find----------------"<<j<<" to "<<k<<"----------------";
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
