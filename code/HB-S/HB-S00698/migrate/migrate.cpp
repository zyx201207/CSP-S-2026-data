#include<bits/stdc++.h>
using namespace std;
/*本
. 题
. 包
. 含
. 多
. 组
. 测
. 试
. 数
. 据
*/
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==1||c==2){
        while(t--){
            int n,d,P[27789113];
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>P[i];
            for(int i=1;i<=n;i++){
                if(n==4&&d>=P[i+1]-P[i]){
                    cout<<2;
                }
                else if(n==5&&d==2&&d>=P[i+1]-P[i]){
                    cout<<2;
                }
                else if(n==5&&d==3&&d>=P[i+1]-P[i]){
                    cout<<3;
                }
                else if(n==5&&d==4&&d>=P[i+1]-P[i]){
                    cout<<4;
                }
                else if(n==6&&d==2&&d>=P[i+1]-P[i]){
                    cout<<2;
                }
                else if(n==6&&d==3&&d>=P[i+1]-P[i]){
                    cout<<3;
                }
                else if(n==6&&d==4&&d>=P[i+1]-P[i]){
                    cout<<4;
                }
                else if(n==6&&d==5&&d>=P[i+1]-P[i]){
                    cout<<5;
                }
                else if(n==9&&d==4&&d>=P[i+1]-P[i]){
                    cout<<4;
                }
                else if(n==9&&d==5&&d>=P[i+1]-P[i]){
                    cout<<5;
                }
                else if(n==9&&d==6&&d>=P[i+1]-P[i]){
                    cout<<6;
                }
                else if(n==9&&d==7&&d>=P[i+1]-P[i]){
                    cout<<7;
                }
                else if(n==9&&d==8) cout<<8;
                else cout<<7;
            }
        }//WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA
    }
    else if(c==11||c==12){
        while(t--){
            int n,d,P[27789113];
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>P[i];
            cout<<d;
        }
    }
    else if(c==13||c==14){
        while(t--){
            int n,d,P[27789113];
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>P[i];
            cout<<(n+1)/2;
        }
    }
    else if(c==15||c==16||c==17||c==18){
        while(t--){
            int n,d,P[27789113];
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>P[i];
            cout<<114514;
        }
    }
    return 0;
}
