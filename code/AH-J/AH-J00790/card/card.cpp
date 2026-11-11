#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
map<int,int>mp;
vector<int>vec;
queue<int>q1,q2;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q1.push(a[i]);
    }
    for(int k=1;k<=n;k++){
        for(int i=k;i<=n;i++){
            bool f=0;
            int j=0;
            int x=a[i];
            while(q2.size()){
                j++;
                int tmp=q2.front();
                q2.pop();
                q2.push(tmp);
                if(tmp==x){
                    f=1;
                    break;
                }
                if(j==i)break;
            }
            if(f){//delete
                while(q2.size()){
                    q2.pop();
                }
            }
            q2.push(a[i]);
        }
        while(q2.size()){//delete it and copy in map
            int x=q2.front();
            mp[x]++;
            q2.pop();
        }
        for(int l=1;l<=n;l++){//be new
            a[l]=q1.front();
            q1.pop();
            q1.push(a[l]);
        }
    }
    for(int i=1;i<=m;i++){
        cout<<mp[i]<<' ';
    }
    return 0;
}
