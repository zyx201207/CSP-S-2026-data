#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
int a[200007];
vector<int> zm;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=i;j<=n;j++){
            zm.push_back(a[j]);
            if(find(zm.begin(),zm.end(),a[j])-zm.begin()<=n-m+1){
                zm.clear();
                zm.push_back(a[j]);
            }
            cout<<;
        }
        cout<<i;
    }
    return 0;
}
/*
• 两张车票对应的座位是否在同一节车厢;
• 两张车票对应的座位是否在同一节车厢的同一排;
• 两张车票对应的座位是否在同一节车厢的同一排,且位于过道的同一侧;
• 两张车票对应的座位是否相邻。
*/
