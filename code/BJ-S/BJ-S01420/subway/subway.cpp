#include<iostream>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int w[N],k[510],a[510][N],t[510][N];
int zh[510][510];//从第i条线路到第j条线路最短换乘时间
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            zh[i][j]=2147483647;
        }
    }
    /*
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int f=1;f<=j[i];f++){
                if(a[i][f]==m){
                    for(int d=1;d<=n;d++){
                        for(int e=1;e<=k[d];e++){
                            zh[j][d]=min(zh[j][d],t[n][f]+t[d][e]);
                        }
                    }
                }
            }
        }
    }
    */
    int st,ed;
    long long ans=0;
    for(int i=1;i<=q;i++){
        cin>>st>>ed;
        ans+=w[st]+w[ed];
        cout<<ans*n<<endl;
        //cout<<ans%45<<" years old Cristiano Ronaldo is the best soccer player in the world!!!"<<endl;
    }/*
    for(int i=1;i<=ans%10;i++) cout<<"SIU!!!"<<" ";
    cout<<"wangsuhengdaociyiyou!!!";
    */
    return 0;
}