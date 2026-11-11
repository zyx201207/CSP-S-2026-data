#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,num[200005],ans;
int sumn;
int ln[200005],rn[200005];
char lc[200005],rc[200005],ch[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >>n;
    for(int i = 1;i <= n;i++){
        cin >> num[i] >> ch[i];
        sumn += num[i];
    }
    int mid = sumn/2;
    int sl = 0,li = 0,ri = 1,sr = 0,i = 1;
    while(sl+num[i] <= mid){
        sl += num[i];
        lc[i] = ch[i];
        ln[i] = num[i];
        li++;
        i++;
    }
    if(sl != mid){
        li++;
        lc[i] = ch[i];
        ln[i] =  mid - sl;
        sl = mid;
        num[i] -= ln[i];
    }
    if(sumn%2 == 1){
        num[i]-=1;
    }
    for(;i <= n;i++){
        sr += num[i];
        rc[ri] = ch[i];
        rn[ri] = num[i];
        ri++;
    }
    ri--;
    i = li;int j = 1;
    while(1){
        if(ln[i] == 0)i--;
        if(rn[j] == 0)j++;
        if(lc[i] == rc[j]){
            if(ln[i]!= rn[j]){
                if(ln[i] > rn[j]){
                    ln[i] -= rn[j];
                    rn[j] = 0;
                }else{
                    rn[j] -= ln[i];
                    ln[i] = 0;
                }
            }else{
                ln[i] = rn[j] = 0;
            }
        }else{
            if(ln[i]!= rn[j]){
                ans += min(ln[i],rn[j]);
                if(ln[i] > rn[j]){
                    ln[i] -= rn[j];
                    rn[j] = 0;
                }else{
                    rn[j] -= ln[i];
                    ln[i] = 0;
                }
            }else{
                ans += min(ln[i],rn[j]);
                ln[i] = rn[j] = 0;
            }
        }
        if(j == ri && i == 1){
            break;
        }
    }
    cout <<ans;
    return 0;
}
