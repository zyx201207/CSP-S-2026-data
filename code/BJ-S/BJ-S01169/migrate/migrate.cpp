#include<bits/stdc++.h>
using namespace std;
int t,c;
long long v,n,u,d,a[2000005],b[2000005];
int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    //cout << c <<' '<<t << endl;
    while(t--){
        //messages(a,0,pirzoif)
        scanf("%lld%lld",&n,&d);
        //cout << "666" << endl;
        //cout << n <<' '<<d << endl;
        for(long long i = 1;i <= n;i++){
            scanf("%lld",&a[i]);
            //cout << a[i] << ' ' << i << endl;
            long long o = 1;
            while(a[i + o] - a[i] <= d){
                b[i] = o;
                o++;
            }

        }
        if(c == 11||c == 12){
            if((a[n] - a[n - 1]) * 2 <= d){
                printf("%lld",n - 3);
            }else{
                printf("%d",0);
            }
            printf("\n");
            continue;
        }
        if(c == 13||c == 14){
            if(n <= 2){
                printf("%d",0);
            }else{
                int cnt = 0;
                if((a[3] - a[1] >= d)){
                    cnt++;
                }
                if(a[n] - a[n - 2]){
                    cnt++;
                }
                printf("%d",cnt);
            }
            printf("\n");
            continue;
            //printf("%d",1);
        }
        long long l = 1,r = 3,cnt = 0;
        while(r <= n){
            long long sum = 0;
            for(long long i = l + 1;i <= r - 1;i++){
                if(a[i] - a[l] < d && a[r] - a[i] < d){
                    sum += pow(2,r - (b[i] + i));

                    if(sum >= 3||sum < 0){
                        break;

                    }
                }
            }
            if(sum == 2){
                cnt++;
            }else if(sum == 0){
                l++;
            }
            r++;
        }

        printf("%lld",cnt);
        if(t != 0){
            printf("\n");
        }
        for(int i = 1;i <= n;i++){
            a[i] = 0,b[i] = 0;
        }
    }
    return 0;
}
