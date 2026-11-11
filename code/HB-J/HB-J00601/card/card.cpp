#include<bits/stdc++.h>
using namespace std;
int n , m;
int a[500009] = {};
vector<int> v[500009];
int cup[500009] = {};
int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int t = 1;t <= n;t++){
		memset(cup , 0 , sizeof(cup));
        for(int c = t;c <= n;c++){
            if(cup[a[c]] != 0){
                for(int i = cup[a[c]] - 1;i < v[t].size();i++){
                    v[t][i] = 0;
                    v[t].push_back(a[c]);
					cup[a[c]] = v[t].size();
                }
            }else{
                v[t].push_back(a[c]);
                cup[a[c]] = v[t].size();
            }
        }
        for(int c = 0;c < v[t].size();c++){
            if(v[t][c] == 0){
                continue;
            }
            //cout << v[t][c] << " ";
        }
        //cout << endl;
    }
    int ans = 0;
    for(int t = 1;t <= m;t++){
		ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 0;j < v[i].size();j++){
                if(v[i][j] == t){
                    ans++;
                    break;
                }
            }
        }
        cout << ans << " ";
    }
    return 0;
}
