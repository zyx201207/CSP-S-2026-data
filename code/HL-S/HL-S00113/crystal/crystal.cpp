#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=2e5+10;
int nums[N];
const int M=1e6+10;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n;
    cin >> m;
    bool flg=0;
    for(int i=1;i<=n;i++){
        cin >> nums[i];
        if(nums[i]!=i){
            flg=1;
        }
    }
    if(flg==0){
        int i=1;
        for(i=1;i<=m;i++){
            m-=i;
            if(m<=0) break;
        }
        cout << i;
    }else{
        bool flg1=0;
        int k=nums[2]-nums[1];
        for(int i=3;i<=n;i++){
            if(nums[i]-nums[i-1]!=k){
                flg1=1;
                break;
            }
        }
        if(flg1==0){
            int i=1;
            for(i=1;i<=m;i++){
                m-=i*k;
                if(m<=0) break;
            }
            cout << i;
        }else{
            int lstans=0;
            sort(nums+1,nums+n+1);
            for(int i=1;i<n;i++){
                int tgt=nums[i];
                int cnt=0;
                int ans=0;
                for(int j=1;j<=n;j++){
                    cnt++;
                    m-=abs(tgt-nums[j]);
                    if(m==0){
                        ans=cnt+1;
                    }else if(m<0){
                        ans=cnt+2;
                    }
                }
                if(m>0){
                    ans=n;
                }
                lstans=max(lstans,ans);

            }
            cout << lstans-3;

//            for(int i=1;i<=n;i++){
//                cout << nums[i] << " " << endl;
//            }
//            long long sum=0;
//            for(int i=1;i<=n;i++){
//                sum+=nums[i];
//            }
//            int ans1=0;
//            int kk=sum/n;
//            int min_idx=1;
//            int minn=0x3f3f3f3f;
//            for(int i=n;i>=1;i--){
//                if(kk-nums[i]<0) break;
//                if(kk-nums[i]<minn){
//                    minn=kk-nums[i];
////                    cout << minn << endl;
//                    min_idx=i;
//                }
//            }
//            int tgt=nums[min_idx];
//            cout << min_idx << ' ' <<tgt << endl;
//            int cnt=0;
//            for(int pp=min_idx-1;pp>=1;pp--){
//                cnt++;
//                m-=(tgt-nums[pp]);
//                if(m==0){
//                    ans1=cnt+2;
//                }else if(m<0){
//                    ans1=cnt+1;
//                }
//            }
//            if(m>0){
//                ans1=cnt+1;
//            }
//            cout << ans1;
//            int ans2=0;
//            if(m*n/2<=50000000){
//                int lastans=0;
//                for(int i=1;i<n;i++){
//                    int tgtt=nums[i];
//                    int cnt=0;
//                    for(int j=i-1;j>=0;i--){
//                        cnt++;
//                        if(m-(tgt-nums[j])==0){
//                            ans2=cnt+2;
//                            break;
//                        }else if(m-(tgt-nums[j])<0){
//                            ans2=cnt+1;
//                            break;
//                        }else{
//                            m-=(tgt-nums[i]);
//                        }
//                    }
//                    lastans=max(lastans,ans2);
//                }
//                cout << max(ans1,lastans);
//
//            }

        }


    }





    return 0;
}

