#include <bits/stdc++.h>
using namespace std;
//262142
int n,m;
int mk[400005],t[400005],cnt,num;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>mk[i];
        t[i]=1;
        cnt++;
    }
    for(int j=30;j>=0;j--){
        num<<=1;
        int mcnt=cnt;
        for(int i=1;i<=n;i++){
            if(!((mk[i]>>j)&1) && t[i]){
                mcnt--;
            }
        }
        if(mcnt<m) continue;
        for(int i=1;i<=n;i++){
            if(!((mk[i]>>j)&1) && t[i]){
                cnt--;
                t[i]=0;
            }
        }
        num++;
    }
    cout<<num;
}
//9:43 AC(?) 9:46 da yang li AC
