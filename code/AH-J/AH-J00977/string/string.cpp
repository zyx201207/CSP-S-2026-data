#include<bits/stdc++.h>
using namespace std;
int a[100000005];
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        char c;
        cin>>a[i]>>c;
        for(int j=1;j<=a[i];j++){
            s+=c;
        }
    }
    int sum=0;
    int e=0,d=s.size()-1;
    while(e!=d){
        if(s[e]!=s[d]){
            sum++;
        }
        e++;
        d--;
    }
    cout<<sum;



    return 0;
}
