#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    int v;
    char c;
    for(int i=0;i<n;i++){
        cin>>v>>c;
        for(int i=0;i<v;i++){
            s+=c;
        }
    }
    long long sum=0;
    for(int i=0,j=s.size()-1;i<j;i++,j--){
        if(s[i]!=s[j]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
