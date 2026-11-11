#include<bits/stdc++.h>
using namespace std;
#define fs first
#define se second
typedef long long ll;
typedef pair<long long, char> pic;
int n;
vector<pic> a;
vector<pic> x;
vector<pic> y;
vector<pic> z;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        ll x;
        char c;
        cin >> x >> c;
        if(i==1 || c != a.back().se){
            a.push_back({x,c});
        }else{
            a.back().fs += x;
        }
        sum += x;
    }
    long long s1 = 0;
    for(int i = 0; i < a.size(); i++){
        s1 += a[i].fs;
        if(s1 > sum/2){
            x.push_back({sum/2 - s1 + a[i].fs, a[i].se});
            break;
        }
        x.push_back(a[i]);
    }   
    s1=0;
    for(int i = a.size()-1; i >= 0; i--){
        s1 += a[i].fs;
        if(s1 > sum/2){
            y.push_back({sum/2 - s1 + a[i].fs, a[i].se});
            break;
        }
        y.push_back(a[i]);
    } 
    long long s2= 0;
    s1 =0;
    for(int i =0, j=0; i < x.size() && j < y.size(); i++){
        s1 += x[i].fs;
        while(j < y.size() && s2 < s1){
            s2 += y[j].fs;
            if(s2>s1){
                z.push_back({s1-s2+y[j].fs, y[j].se});
                y[j].fs -= z.back().fs;
                s2 -= y[j].fs;
                //if(s2!=s1) cout << -1;
                //if(y[j].fs <0) cout << -1;
                break;
            }
            z.push_back(y[j]);
            j++;
        }
    }
    //if(s2 < s1) cout << -1;
    // for(auto it : x){
    //    cout << it.fs << " " << it.se << endl;
    // }
    // cout << endl;
    // for(auto it : z){
    //    cout << it.fs << " " << it.se << endl;
    // }
    long long ans = 0;
    s1=0, s2=0;
    for(int i = 0, j = 0; i < x.size() && j < z.size(); i++){
        //cout << i << " ";
        s1 += x[i].fs;
        while(j < z.size() && s2 < s1){
            //cout << j << " ";
            s2 += z[j].fs;
            if(z[j].se != x[i].se){
                ans += z[j].fs;
            }
            j++;
        }
    }
    //if(s2 < s1) cout << -1;
    cout << ans << endl;
    return 0;
}