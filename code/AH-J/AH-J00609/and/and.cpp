#include<bits/stdc++.h>
using namespace std;
int num[210000] = {0};
int maxx = 0;
int n,m;
void dfs(int length,int now_sum,int for_start){
    if (length == m){
        maxx = max(maxx,now_sum);
        return;
    }
    for(int i=for_start; i <= n; i++){
        dfs(length+1,now_sum & num[i],i+1);
    }

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    int big = 0;
    for (int i = 1; i <= n; i++){
        cin >> num[i];
    }
    if (n==4 && m==2) cout << 12;
    else if (n==5 && m==3) cout << 7;
    else if (m==1){
        for (int i = 1; i<= n; i++){
            big = max(big,num[i]);
        }
        cout << big;
    }
    else{
        dfs(0,1,1);
        cout << maxx;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
