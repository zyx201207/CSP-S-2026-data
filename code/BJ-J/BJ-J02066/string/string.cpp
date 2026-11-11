#include<bits/stdc++.h>
using namespace std;
struct node{
    long long z;
    char w;
};
int n, a[100010], x;
char c[100010];
node cnt[100010];
long long number, mt, number1, mid, m;
bool f, f1;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
        number += a[i];
    }
    if(number%2 != 0){
        f = 1;
    }
    for(int i = 1; i <= n; i++){
        number1 += a[i];
        if(number1-a[i] < number/2 && number/2 <= number1){
            mid = i;
            m = number/2-number1+a[i];
            break;
        }
    }
    for(int i = 1; i <= n; i++){
        if(c[i] == cnt[x].w){
            if(mid == i && f1 == 0){
                mid = x;
                m += cnt[x].z;
                f1 = 1;
            }
            cnt[x].z += a[i];
        }else{
            x++;
            if(mid == i && f1 == 0){
                mid = x;
                f1 = 1;
            }
            cnt[x].z = a[i];
            cnt[x].w = c[i];
        }
    }
    if(f == 1){
        if(m == cnt[mid].z){
            cnt[mid+1].z -= 1;
        }else{
            cnt[mid].z -= 1;
        }
    }
    for(int i = 1; i <= mid && m != 0; ){
        if(i == mid && m != cnt[i].z){
            if(x != mid){
                if(cnt[i].w != cnt[x].w){
                    mt += cnt[x].z;
                    cnt[i].z -= cnt[x].z;
                    m -= cnt[x].z;
                    x--;
                }else{
                    cnt[i].z -= cnt[x].z;
                    m -= cnt[x].z;
                    x--;
                }
            }else{
                break;
            }
            continue;
        }
        if(cnt[i].w != cnt[x].w){
            if(cnt[i].z >= cnt[x].z){
                mt += cnt[x].z;
                cnt[i].z -= cnt[x].z;
                if(mid == i){
                    m -= cnt[x].z;
                }
                x--;
            }else{
                mt += cnt[x].z-cnt[i].z;
                cnt[x].z -= cnt[i].z;
                i++;
            }
        }else{
            if(cnt[i].z >= cnt[x].z){
                cnt[i].z -= cnt[x].z;
                if(mid == i){
                    m -= cnt[x].z;
                }
                x--;
            }else{
                cnt[x].z -= cnt[i].z;
                i++;
            }
        }
    }
    cout << mt;
    return 0;
}
