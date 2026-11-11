#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
bool f;
long long a[510001],c,m,n,s[310001],t[600001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=c;j++) t[j]=0;
        c=0;
        // 第j局，跳过(j-1)张，即从i开始
        for(int j=i;j<=n;j++){
            // 出第j张牌
            f=false;
            for(int k=1;k<=c;k++){
                if(f){
                    t[k]=-1;
                    continue;
                }
                if(a[j]==t[k]){
                    // 收走这张牌及其后面所有牌
                    t[k]=-1;
                    f=true;
                }
            }
            // 放在最右边
            t[++c]=a[j];
            //cout<<c<<" ";
            //for(int k=1;k<=c;k++) cout<<t[k]<<" ";
            //cout<<endl;
        }

        //cout<<i<<"end ";
        //for(int k=1;k<=c;k++) cout<<t[k]<<" ";
        //cout<<endl<<endl;

        // 检查桌上1~m的牌
        for(int j=1;j<=m;j++){
            for(int k=1;k<=c;k++){
                if(t[k]==j){
                    s[j]++;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=m;i++) cout<<s[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
