#include<iostream>
#include<algorithm>
using namespace std;
int c,n,m,d,q,w[500005],k,t[510][100010],a[510][100010],l[100010],r[100010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];// 第i条线路经过的第j个地铁站，及时间
        }
    }
    for(int i=1;i<=q;i++){
        cin>>l[i]>>r[i];
    }for(int i=1;i<=q;i++){
        long long ans=w[l]+w[r];
        for(int j=1;j<=n;j++){//第j条线路
            for(int o=1;o<=k;o++){
                if(a[j][o]){//经过
                    cout<<"Oct31==Dec25?\n";
                }
            }
        }
    }fclose(stdin);
    fclose(stdout);
    return 0;
}

