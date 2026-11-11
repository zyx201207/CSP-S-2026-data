#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
struct node{
        int to;
        char c;
}ls[200010];
signed main(){
        freopen("string.in","r",stdin);
        freopen("string.out","w",stdout);
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n;
        int cnt = 0,flag = 0;
        cin >> n;
        for(int i = 1;i <= n;i++){
                cin >> ls[i].to >> ls[i].c;
                cnt += ls[i].to;
        }
        cnt = (cnt + 1) / 2;
		int j;
        for(j = 1;j <= n;j++){
                flag += ls[j].to;
                if(flag >= cnt){
                        if(flag > cnt)ls[j].to--;
                        break;
                }
        }
        int l = 1,r = n,ans = 0;
        while(l <= r){
			if(ls[l].to == ls[r].to){
				if(ls[l].c != ls[r].c)ans += ls[r].to;
                l++;
                r--;
            }
            else if(ls[l].to > ls[r].to){
				if(ls[l].c != ls[r].c)ans += ls[r].to;
				ls[l].to -= ls[r].to;
				r--;
			}
			else{
                if(ls[l].c != ls[r].c)ans += ls[l].to;
                ls[r].to -= ls[l].to;
				l++;
            }
        }   
        cout << ans;
        return 0; 
}
