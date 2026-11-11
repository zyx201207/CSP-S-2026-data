#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int re[N];
int desk[N];
pair<bool,int> check_re(int ndi,int ncv){
    for(int i=1;i<=ndi;i++){
        if(ncv == desk[i]){
            for(int j=i;j<=n;j++) desk[j] = 0;
            return make_pair(true,i);
        }
    }
    return make_pair(false,ndi);
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int ju=1;ju<=n;ju++){
        memset(desk,0,sizeof(desk));
        int st_card_index=ju;
        int now_desk_index=1;
        for(int i=ju;i<=n;i++){
            int now_card_value=a[i];
            pair<bool,int> cr=check_re(now_desk_index,now_card_value);
            if(cr.first){
                now_desk_index = cr.second;
            }
            desk[now_desk_index] = now_card_value;
            now_desk_index++;
        }
        for(int i=1;i<=now_desk_index;i++){
            re[desk[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<re[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
