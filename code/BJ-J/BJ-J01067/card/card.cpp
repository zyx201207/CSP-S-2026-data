#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,pos,num[200005],a[200005],cnt[200005];
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> num[i];
    }
    memset(cnt,0,sizeof(cnt));
    for(int i = 1;i <= n;i++){
        memset(a,0,sizeof(a));
        int pos = 0;
        for(int j = i;j <= n;j++){
            int flag = 0;
            for(int k = 1;k <= pos;k++){
                if(num[j] == a[k]){
                    flag = k;
                    break;
                }
            }
            if(flag > 0){
                pos = flag;
                a[pos] = num[j];
            }
            else{
                pos++;
                a[pos] = num[j];
            }
        }
        for(int i = 1;i <= pos;i++){
            cnt[a[i]]++;
        }
    }
    for(int i = 1;i <= m;i++){
        cout << cnt[i] << " ";
    }
	return 0;
}
