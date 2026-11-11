#include <bits/stdc++.h>
using namespace std;
long long number(vector<long long> vec,int m,int j){
    long long a = vec[j];
    for(int i = j+1;i<m+j;i++){
        a = a&vec[i];
    }
    return a;
}
int main(){
    freopen("and1.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long ms = 0;
    cin >> n >> m;
    vector<long long> vec(n);
    for(int i = 0;i<n;i++){
        cin >> vec[i];
    }
    sort(vec.begin(),vec.end(),greater<long long>());
    for(int i = 0;i<n;i++){
        long long s = number(vec,m,i);
        ms = max(s,ms);
        if(vec[i] <= ms){
            break;
        }
    }
    cout << ms;
}
