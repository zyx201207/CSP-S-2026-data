#include <bits/stdc++.h>
using namespace std;

long long n,sum=0,summ,ans=0,z;
char zc;
string t;
struct N{
    long long num;
    char s;
}a[200020];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin >> n;
    for (long long i=1;i<=n;i++){
        cin >> a[i].num;
        sum+=a[i].num;
        cin >> a[i].s;
    }
    sum=sum/2+1;
    summ=sum;
    for (long long i=1;i<=n;i++){
        if (a[i].num<summ){
            summ-=a[i].num;
        }
        else{
            if(a[i].num==summ && (sum%2)==0){
                if (a[i+1].s!=a[i].s){
                    ans++;
                }
                z=i;
                zc=a[i].s;
            }
            else{
                z=i;
                zc=a[i].s;
            }
            break;
        }
    }
    for (long long i=1;i<=z;i++){
        long long len=a[i].num;
        for (long long j=n;len>=0;j--){
            if (a[j].s!=a[i].s){
                if (a[j].num<len){
                    len-=a[j].num;
                    ans+=a[j].num;
                }
                else{
                    ans+=len;
                    break;
                }
            }
            else{
                if(a[j].num>=len) break;
                else{
                    len-=a[j].num;
                }
            }
        }
    }
    cout << ans;
	return 0;
}
