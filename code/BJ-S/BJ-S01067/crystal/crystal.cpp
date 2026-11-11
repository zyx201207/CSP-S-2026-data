//long long ###
//int
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    queue<long long>q;
    long long ot=0,last=a[1];
    for(long long i=1;i<=n;i++){
        ot+=q.size()*(a[i]-last);
        q.push(a[i]);

        while(ot>m&&(!q.empty())){
            ot-=a[i]-q.front();
            q.pop();
        }
        //then
        last=a[i];
        if(q.size()>ans){
            ans=q.size();
        }

    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
