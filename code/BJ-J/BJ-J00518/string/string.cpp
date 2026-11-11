#include<bits/stdc++.h>

using namespace std;

struct node{
    long long cnt,l,r;
    char c;
};
long long n,m;
node lst[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>lst[i].cnt>>lst[i].c;
        lst[i].l=lst[i-1].r+1;
        lst[i].r=lst[i].l+lst[i].cnt-1;
        m+=lst[i].cnt;
    }

    long long l=1,r=n,ans=0;//l,r dang qian shi ji de kuai
    while(l<=r){
        long long cnt=0;
        while(l<=r){
            if(cnt+lst[r].cnt>lst[l].cnt){
                break;
            }
            cnt+=lst[r].cnt;
            if(lst[r].c!=lst[l].c){
                ans+=lst[r].cnt;
            }
            r--;
        }

        if(cnt<lst[l].cnt){
            if(lst[r].c!=lst[l].c){
                ans+=lst[l].cnt-cnt;
            }
            lst[r].r-=lst[l].cnt-cnt;
            lst[r].cnt-=lst[l].cnt-cnt;
        }
        l++;
    }

    cout<<ans;
    return 0;
}
