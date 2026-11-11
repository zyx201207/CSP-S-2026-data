#include<iostream>
using namespace std;
int sum[1005],a[100005],l[100005] = {};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m,n,x = 0;
    cin >> n >> m;
    for(int s = 0;s <= n;s++){
        cin >> a[s];
    }
    for(int i = 0;i < n;i++){
        for(int k = 0;k <= n;k++){
            if(l[k] == a[i]){
                for(int j = k;j <= i-k;j++){
                    l[j] = 0;//clear
                }
            }
        }
        l[i] = a[i];//when the round end
        x++;
        //choose number
        for(int q = 0;q <= m;q++){
            sum[l[q]]++;
        }
    }

    for(int p = 1;p <= m;p++){
        cout << sum[p] << " ";
    }
}