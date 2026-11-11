#include<bits/stdc++.h>
using namespace std;

/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

2
2 a
3 a
*/

const int MAXN = 2e5 +5;

struct line{
    int num;
    char key;
};

long long n,k,ans=0,head=1,tail;
line arr[MAXN];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    
    cin.tie(nullptr);
    //ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].num >> arr[i].key;
    }
    tail = n;

    while(head<tail){
        k = min(arr[head].num,arr[tail].num);
        if(arr[head].key != arr[tail].key) ans += k;
        arr[head].num-=k;
        arr[tail].num-=k;
        if(!arr[head].num)head++;
        if(!arr[tail].num)tail--;
    }

    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
