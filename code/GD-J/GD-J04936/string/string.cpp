#include<bits/stdc++.h>
using namespace std;
string s;
void f(int sum, char c){
    for(int i=0;i<sum;i++){
        s+=c;
    }
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long n;
    cin>>n;
    for(int i=0;i<n;i++){
        long long sum;
        char c;
        cin>>sum>>c;
        f(sum, c);
    }
    int cnt=0;
    for(int i=0;i<=s.size()/2;i++){
        char a=s[i];
        char b=s[s.size()-i-1];
        if(a!=b){
            cnt++;
            s[s.size()-i-1]=a;
        }
    }
    cout<<cnt;
    return 0;
}
