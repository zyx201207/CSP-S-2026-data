#include <bits/stdc++.h>
using namespace std;
int n;
long long int ans=0;
struct N{
    int w,nm;
};
N num[1000000];
int main(){
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i].w;
        string temp;
        cin>>temp;
        num[i].nm=int(temp[0]-'a');
    }
    int l=0,r=n-1,rn=0;
    while(l<r){
        int ll = num[l].w;
        int rr = 0;
        while(ll>rr){
            if(ll-rr>=num[r].w-rn){
                if(num[l].nm!=num[r].nm){
                    ans+=num[r].w-rn;
                }
                rr+=num[r].w-rn;
                rn=0;
                r--;
            }
            else{
                int x=ll-rr;
                if(num[l].nm!=num[r].nm){
                    ans+=x;
                }
                rn+=x;
                rr+=x;
            }
        }
        l++;
    }
    cout<<ans;
    return 0;
}
