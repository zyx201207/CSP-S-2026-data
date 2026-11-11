#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
int c,n,d,ans,t;
int island[1000005];
queue<int>wy;
int low(int a,int b){
    if(island[a]+d>=b)return 1;
    int carry=1;
    for(int i=1;i<=n;i++){
        if(island[a]+d<island[i])break;
        carry=i;
    }
    cout<<low(island[carry],b)+1;
    return (low(island[carry],b)+1);
}
bool find(int a){
    for(int i=1;i<=n;i++){
        if(island[i]==a)return true;
    }
    return false;
}
int fd(int a){
    for(int i=1;i<=n;i++){
        if(island[i]==a)return i;
    }
    return 0;
}
int way(int a,int b){
    while(!wy.empty()){
        wy.pop();
    }
    if(a==b){
        return 1;
    }
    for(int i=1;i<=d;i++){
        if(find(island[a]+i)){
            wy.push(way(island[a]+i,b));
            //return way(island[a]+i,b)+1;
        }
    }
}
bool ck(){
    for(int i=3;i<=n;i++){
        if(island[i-1]-island[i-2]!=island[i]-island[i-1]){
            //cout<<"false";
            return false;
        }
    }
    //cout<<"true";
    return true;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>t>>c;
    /*
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(2*d-(island[j]-island[i])==1&&find(island[i]+d)&&find(island[i]+d-1)){
                    cout<<island[i]<<" "<<island[j]<<endl;
                ans++;
            }
        }
    }
    cout<<ans;

    way(1,4);
    while(!wy.empty()){
        cout<<wy.front()<<endl;
        wy.pop();
    }
    */
    while(c--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>island[i];
        }
        ans=0;
        //for(int i=1;i<=n;i++){
        //    cout<<island[i];
        //}
        if(ck()){

            int cc=island[2]-island[1];
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(island[j]-island[i]==3*d){
                        ans++;
                    }
                }
            }
            cout<<ans;
        }
        else if(island[n]-island[1]<=2*d){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(2*d-(island[j]-island[i])==1&&find(island[i]+d)&&find(island[i]+d-1)){
                            //cout<<island[i]<<" "<<island[j]<<endl;
                        ans++;
                    }
                }
            }
            cout<<ans;
        }else{
            cout<<endl;
        }
    }
    return 0;
}
