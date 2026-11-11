#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    vector<char>a;
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        long long cnt;
        cin>>cnt;
        char x;
        cin>>x;
        for(long long i=1;i<=cnt;i++){
            a.push_back(x);
        }
    }
    long long ans=0;
    long long i=0,j=a.size()-1;
    while(i<j){

        if(a[i]!=a[j]){
            ans++;
        }
        i++;
        j--;
    }
    cout<<ans<<endl;





    return 0;
}
