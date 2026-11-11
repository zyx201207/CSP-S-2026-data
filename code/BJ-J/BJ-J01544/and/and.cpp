#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int>b1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b1.push_back(a[i]);
    }
    int s=30,ans=0;
    while(true){
        map<int,int>cnt;
        for(auto x:b1){
            for(int i=s;i>=1;i--)
                cnt[i]+=(x>>i-1)&1;
        }
        int p=s;
        while(p>=1){
            if(cnt[p]>=m)
                break;
            p--;
        }
        if(p==0)
            break;
        else if(cnt[p]==m){
            ans=INT_MAX;
            for(auto x:b1){
                if((x>>p-1)&1)
                    ans&=x;
            }
            break;
        }else{
            ans+=1<<p-1;
            vector<int>b2;
            for(auto x:b1){
                if((x>>p-1)&1)
                    b2.push_back(x);
            }
            b1=b2;
            s=p-1;
        }
//        for(auto x:b1)
//            cout<<x<<" ";
//        cout<<endl;
    }
    printf("%d",ans);
//    cout<<endl<<clock();
    return 0;
}
/*
1111
1010
1010
*/
