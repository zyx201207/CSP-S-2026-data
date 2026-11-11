#include<bits/stdc++.h>
using namespace std;
struct stu{
    long long num;
    char c;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,sum=0;
    cin>>n;
    deque<stu> q;
    for(long long i=0;i<n;i++){
        long long k;
        char p;
        cin>>k>>p;
        sum+=k;
        q.push_back({k,p});
    }
    long long ans=0;
        while(q.size()>1){
            stu fro=q.front();
            stu bac=q.back();
            if(fro.c==bac.c){
                if(fro.num>bac.num){
                    q.front().num-=bac.num;
                    q.pop_back();
                }else if(fro.num==bac.num){
                    q.pop_back();
                    q.pop_front();
                }else{
                    q.back().num-=fro.num;
                    q.pop_front();
                }
            }else{
                if(fro.num>bac.num){
                    q.front().num-=bac.num;
                    ans+=bac.num;
                    q.pop_back();
                }else if(fro.num==bac.num){
                    q.pop_back();
                    q.pop_front();
                    ans+=fro.num;
                }else{
                    q.back().num-=fro.num;
                    ans+=fro.num;
                    q.pop_front();
                }
            }
        }
    cout<<ans;
    return 0;
}
