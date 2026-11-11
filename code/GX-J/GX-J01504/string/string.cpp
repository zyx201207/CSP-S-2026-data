#include  <bits/stdc++.h>
#define LL long long
using namespace std;
LL n, ai, cnt=0, a[2000005];
char s[200005],si, p[200005];
//char <vector> v;
int main(){
    freopen("string3.in","r",stdin);
    freopen("string3.out","w",stdout);
    string str,unstr;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ai >> si;
        s[i]=si;
        a[i]=ai;
        /*
        for(int j=0;j<ai;j++){
            v.push_back(si);
        }
        */
    }
    /*
    if(v.size()%2==1){
        for(int i=0;i<v.size();i++){
            if(i<v.size()/2+1)
                continue;
            else {
                if(v[i]==v.size() - 1 - v[i])DUI CHENG{
                    continue;
                }
                else {
                    cnt++;
                    v[i] = v.size() - 1 - v[i];
                }
            }
        }
    }
    else {
        for(int i=0;i<v.size();i++){
            if(i<v.size()/2)
                continue;
            else {
                if(v[i]==v.size() - 1 - v[i])DUI CHENG{
                    continue;
                }
                else {
                    cnt++;
                    v[i] = v.size() - 1 - v[i];
                }
            }
        }
    }
    */

    for(int i = n;i >= 0; i--){
        p[n-i]=s[i-1];
    }
    for(int i=0;i<n;i++){
        //cout << p[i] << ' '<< s[i] << a[i] <<endl;
        if(p[i]==s[i]) {
            //cout << '1';
        }
        else {
            cnt += a[i];
        }
    }

    cout << cnt / 2;
    return 0;
}
