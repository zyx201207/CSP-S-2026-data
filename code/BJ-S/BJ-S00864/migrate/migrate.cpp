#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[1001010],ans[1000010][2],answer;
queue<int>q;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        answer=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            ans[i][0]=ans[i][1]=0;
        }
        for(int i=1;i<=n;i++){
            for(int i=1;i<=n;i++){

                ans[i][0]=ans[i][1]=0;
            }
            q.push(i);
            while(!q.empty()){
                int e=q.front();
                q.pop();
                int i=e+1;
                while(a[i]-a[e]<=d&&i<=n){
                    if(ans[i][0]==0||ans[e][0]+1==ans[i][0]){
                        ans[i][0]=ans[e][0]+1;
                        ans[i][1]++;
                        q.push(i);
                    }
                    i++;
                }
                i=e-1;
                while(a[i]-a[e]<=d&&i>0){
                    if(ans[i][0]==0||ans[e][0]+1==ans[i][0]){
                        ans[i][0]=ans[e][0]+1;
                        ans[i][1]++;
                        q.push(i);
                    }
                    i--;
                }
            }
            for(int j=i;j<=n;j++){
                //cout<<n<<' '<<i<<' '<<ans[j][1]<<endl;
                if(ans[j][1]==2&&i!=j){
                    answer++;

                }
            }//cout<<1<<endl;
        }
        cout<<answer<<endl;



    }
}
