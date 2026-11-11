#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],max_;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
        //cout << a[i] << endl;
    }
    sort(a + 1,a + n + 1);
    //b[1] = a[1];

    /*for(long long i = 1;i <= n;i++){
        b[i] = a[i] - a[i - 1];

    }*/

    for(long long i = 1;i <= n;i++){
        long long now_nember = m,now_th = i;
        while(now_nember >= 0 && now_th >= 1){
            //if(i == 4){
                //cout << now_nember << ' ' <<a[now_th]<<' '<<i<<' '<<a[i]<<endl;
            //}


            now_nember -= a[i] - a[now_th];
            now_th--;
            //if(i == 4){
                //cout << now_nember << ' ' <<a[now_th]<<' '<<i<<' '<<a[i]<<endl;
            //}





        }
        max_ = max(max_,i - now_th);
        //cout << "   " << max_ << ' ' << now_th << ' ' << i << ' ' <<now_nember << endl;
    }
    printf("%lld",max_);
    return 0;

}
