#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],b[30],c[30]={1},ans=INT_MAX;
vector<int>e,ee;
void ok(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    memset(b,0,sizeof(b));
    for(int i=0;i<e.size();i++){
        int x=a[e[i]];
        if(!x)continue;
        for(int i=30;i>=0;i--){
            if(x>=c[i]){
                b[i]++;
                x-=c[i];
            }
        }
    }
    return ;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=30;i++){
        c[i]=(c[i-1]<<1);
    }
    //?
    ans=INT_MAX;
    //cout<<"\n";
;    for(int i=1;i<=n;i++){
        e.push_back(i);
        cin>>a[i];
    }
    //cout<<ans<<"\n";
    ok();
    for(int i=30;i>=0;i--){
        //cout<<"e"<<e.size()<<"i"<<i<<"\n";
        //for(int j=0;j<e.size();j++){
        //    cout<<e[j]<<" ";
        //}
        //cout<<"\n\n";
        //for(int j=0;j<=30;j++)cout<<b[j];
        //cout<<"\n\n\n";
        if(b[i]<m)continue;
        if(b[i]==m){
            for(int j=0;j<e.size();j++){
                if(a[e[j]]<c[i])continue;
                    //cout<<ans<<" "<<a[e[j]]<<"\n";
                ans&=a[e[j]];
            }
            cout<<ans;
            //cout<<"?";
            return 0;
        }
        if(b[i]>m){
                //cout<<"???"<<"\n";
            for(int j=0;j<e.size();j++){
                if(a[e[j]]>=c[i])ee.push_back(e[j]);
            }
            e.clear();
            for(int j=0;j<ee.size();j++)e.push_back(ee[j]);
            ee.clear();
            ok();
        }
        //cout<<e.size()<<"\n";
        //for(int i=0;i<e.size();i++){
        //    cout<<e[i]<<" ";
        //}
        //cout<<"\n";
    }
    ans=INT_MAX;//什么叫前面定义为INT_MAX后面直接变成INT_MAX/2了，这是人话吗？
    //cout<<INT_MAX<<" "<<ans<<"\n";
    for(int i=0;i<m;i++){
        //cout<<ans<<" "<<a[e[i]]<<"\n";
        ans&=a[e[i]];
    }
    cout<<ans;
    return 0;
}
