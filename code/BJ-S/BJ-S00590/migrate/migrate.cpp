#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,c,t,d;
int a[N],inx;
int dis[10010][10010],cnt;
string s="";
unordered_map<string,int> ans;
void mak(int p,int q){
    s="";
    while(p){
        int x=p%10;
        p=p/10;
        if(x==0)s=s+'0';
        else if(x==1)s=s+'1';
        else if(x==2)s=s+'2';
        else if(x==3)s=s+'3';
        else if(x==4)s=s+'4';
        else if(x==5)s=s+'5';
        else if(x==6)s=s+'6';
        else if(x==7)s=s+'7';
        else if(x==8)s=s+'8';
        else if(x==9)s=s+'9';
    }
    while(q){
        int x=q%10;
        q=q/10;
        if(x==0)s=s+'0';
        else if(x==1)s=s+'1';
        else if(x==2)s=s+'2';
        else if(x==3)s=s+'3';
        else if(x==4)s=s+'4';
        else if(x==5)s=s+'5';
        else if(x==6)s=s+'6';
        else if(x==7)s=s+'7';
        else if(x==8)s=s+'8';
        else if(x==9)s=s+'9';
    }
}
/*

*/
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(a[1]<=0){
            int x=-a[1]+1;
            for(int i=1;i<=n;i++){
                a[i]+=x;
            }
        }
        memset(dis,0x3f,sizeof(dis));
        for(int l=1;l<=n;l++){
            for(int r=l+1;r<=n;r++){
                if(a[r]-a[l]<=d){
                   dis[l][r]=dis[r][l]=1;
                }else{
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++){
            dis[i][i]=0;
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dis[i][j]>dis[i][k]+dis[k][j]){
                        dis[i][j]=dis[i][k]+dis[k][j];
                    }else if(dis[i][j]!=0x3f3f3f3f&&dis[i][j]==dis[i][k]+dis[k][j]){
                        string s2=s;
                        ans[s2]++;
                    }
                }
            }
        }
        for(auto it:ans){
            if(it.second==2)cnt++;
        }
        cout<<cnt<<"/n";
        memset(dis,0,sizeof(dis));
        memset(a,0,sizeof(a));
        ans.clear();
    }

    return 0;
    fclose(stdin);
    fclose(stdout);
}
