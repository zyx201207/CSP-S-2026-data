#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,mm;
int a[20005];
int m[20005];
map<int,int> mp;//存出现在哪里
int ans[20005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>mm;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int l=1,r=0;
       // cout<<"&&&&&"<<i<<endl;
        for(int j=i;j<=n;j++){
                //cout<<l<<" "<<r<<" "<<a[j];
            int k=a[j];
            if(mp[k]==0){
               // cout<<'a';
                r++;
                m[r]=k;
                mp[k]=r;
            }else{
               // cout<<'b';
                int t=mp[k];
               // cout<<endl<<t<<" "<<r<<"*";
                for(int x=t;x<=r;x++){
                    int y=m[x];
                //    cout<<y<<"^";
                    mp[y]=0;
                }

                r=t;//
                mp[k]=r;
            //    cout<<mp[2];

            }
         //   cout<<endl;

        }
        for(int j=1;j<=r;j++){
            int s=m[j];
        //    cout<<s<<"&&";
            ans[s]++;
        }
        for(int j=1;j<=n;j++){
            mp[j]=0;
            m[j]=0;
        }
    }
    for(int i=1;i<=mm;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
