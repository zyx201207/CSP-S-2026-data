#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[1010],t[1010],w[100010],k[1010],l[1010][1010],ll[1010],tim[1100][1100],ans[100100];
int x,y;
queue<int> que;
bool bol[100100];
int main(){
    freopen("subway2.in","r",stdin);
    //freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[j]>>t[j];

        }
        for(int j=1;j<=k[i];j++){
            for(int kk=j+1;kk<=k[i];kk++){
                l[j][ll[j]++]=a[kk];
                if(tim[j][a[kk]]){
                    tim[j][a[kk]]=min(tim[j][a[kk]],t[j]+t[a[kk]]);
                }else{
                    tim[j][a[kk]]=t[j]+t[a[kk]];
                }


            }
        }

    }
    while(q--){

        cin>>x;
        cin>>y;
        for(int i=1;i<=n;i++){
            ans[i]=0;
        }
        que.push(x);
        ans[x]=w[x]+w[y];
        while(!que.empty()){

            int e=que.front();
            que.pop();
            for(int i=1;i<=ll[e];i++){
                if(!bol[i]||ans[e]+tim[e][i]<ans[i]){
                        bol[i]=1;

                    ans[i]=ans[e]+tim[e][i];
                    que.push(i);
                }
            }

        }/**/
        cout<<ans[y]<<endl;
    }

    return 0;



}
