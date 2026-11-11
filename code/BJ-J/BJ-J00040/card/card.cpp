#include <bits/stdc++.h>
using namespace std;
int d[500005],a[300005],z[500005];
queue<int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> d[i];
    }
    for(int i = 1;i<= n;i++){
        for(int j = i;j <= n;j++){
            q.push(d[j]);
        }
        int le = 0;
        while(!q.empty())
        {
            int k = q.front();
            q.pop();
            if(le == 0){
                le++;
                z[le] = k;
            }
            else{
                bool f = false;
                int l = 1;
                while(l <= le)
                    if(f){
                        for(int j = l;j <= le;j++){
                            z[l]=z[l+1];
                        }
                        le--;
                        l--;
                    }
                    else
                    {
                        if(z[i] == k){
                            f = true;
                            for(int j = l;j <= le;j++){
                                z[l]=z[l+1];
                            }
                            le--;
                            l--;
                        }
                    }
                    l++;
                }
                le++;
                z[le] = k;
            }
        }
        for(int j = 1;j <= le;j++)
        {
            a[z[j]]++;
        }
    }
    for(int i = 1;i <= m;i++){
        cout << a[i] << " ";
    }
    return 0;
}
