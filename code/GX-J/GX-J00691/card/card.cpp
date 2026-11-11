#include<bits/stdc++.h>
using namespace std;
const int MAXn = 2e5+10;
int n,a[MAXn],m;
bool b[MAXn];
int ans[MAXn];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);

    for(int card = 1 ; card <= n ; card++){ //进行第card局
        //cout<<"card:"<<card<<'\n';
        stack<int> dask;//桌面上的牌
        memset(b,0,sizeof(b));//b[k] = 0 : 桌面上没有点数为k的牌
        for(int i = card ; i <= n ; i++){
            if(b[a[i]] == 0){//桌面上没有点数为a[i]的牌
                dask.push(a[i]);//将这张牌放在最右端
                b[a[i]] = 1;
            }
            else{
                while(b[a[i]] == 1){//桌面上原来点数为a[i]的牌及其右侧的所有牌收走
                    int pop_card = dask.top();
                    dask.pop();
                    b[pop_card] = 0;
                }
                dask.push(a[i]);//放上新打出的a[i];
                b[a[i]] = 1;
            }
        }
        while(!dask.empty()){
            int ti = dask.top();
            ans[ti]++;
            //cout<<ti<<' ';
            dask.pop();
        }
        //cout<<'\n';
    }

    for(int i = 1 ; i <= m ; i++) printf("%d ",ans[i]);
    return 0;
}
