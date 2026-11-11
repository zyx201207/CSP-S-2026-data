#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
struct node{
    int cnt;
    char c;
}a[N];

long long cur,len,ans;
long long n,mid,sal[N],sar[N];//第几个单词是中点

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].cnt >> a[i].c;
        len += a[i].cnt;
    }

    for(int i = 1;i <= n;i++){
        sal[i] = cur;
        cur += a[i].cnt;
        sar[i] = cur-1;
    }
    mid = len/2;
    //cout << mid <<endl;
    for(int i = 1;i <= n;i++){
        //cout <<sal[i] <<" " << sar[i] <<"\n";
    }
    sal[0] = sar[0] = -1;
    for(int i = 1;i <= n;i++){
        if(sal[i] > mid){//都在右侧
            long long r = len - sal[i]-1;
            long long l = len - sar[i]-1;
            int posl = lower_bound(sal+1,sal+n+1,l)-sal;
            if(sal[posl] > l)posl--;
			int posr = upper_bound(sar+1,sar+n+1,r)-sar;//第一个小于
			if(sar[posr-1] == r)posr--;
			//cout << l <<" "<<r << endl;
			//cout << posl <<" "<<posr << endl;
			if(posl == posr){
                ans += a[i].cnt * (a[i].c != a[posl].c);
			}
			else{
                if(posr - posl == 1){
                    ans += (r-sal[posr]+1)*(a[i].c != a[posr].c);
                    ans += (sar[posl]-l+1)*(a[i].c != a[posl].c);
                }
                else{
                    ans += (r-sal[posr]+1)*(a[i].c != a[posr].c);
                    ans += (sar[posl]-l+1)*(a[i].c != a[posl].c);
                    for(int j = posl+1;j <= posr-1;j++){
                        ans += a[j].cnt * (a[j].c != a[i].c);
                    }
                }
			}

			//cout <<ans<<endl;
        }
    }
    //处理跨海大桥
    for(int i = 1;i <= n;i++){
        if(sal[i] <= mid && sar[i] >= mid){
            long long ll = mid+1;
            long long rr = sar[i];
            if(ll <= rr){
                long long l = len - rr - 1;
                long long r = len - ll - 1;
                int posl = lower_bound(sal+1,sal+n+1,l)-sal;
                if(sal[posl] > l)posl--;
                int posr = upper_bound(sar+1,sar+n+1,r)-sar;//第一个小于
                if(sar[posr-1] == r)posr--;
                //cout << l <<" "<<r << endl;
                //cout << posl <<" "<<posr << endl;
                if(posl == posr){
                    ans += (rr-ll+1) * (a[i].c != a[posl].c);
                }
                else{
                    if(posr - posl == 1){
                        ans += (r-sal[posr]+1)*(a[i].c != a[posr].c);
                        ans += (sar[posl]-l+1)*(a[i].c != a[posl].c);
                    }
                    else{
                        ans += (r-sal[posr]+1)*(a[i].c != a[posr].c);
                        ans += (sar[posl]-l+1)*(a[i].c != a[posl].c);
                        for(int j = posl+1;j <= posr-1;j++){
                            ans += a[j].cnt * (a[j].c != a[i].c);
                        }
                    }
                }
            }
        }

    }
    cout <<ans;
    return 0;
}
