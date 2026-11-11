#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    vector<char> a;
    cin>>n;
    for(int i=0;i<n;i++){
        int x1;
        char x2;
        cin>>x1>>x2;
        for(int j=0;j<x1;j++){
            a.push_back(x2);
        }
    }
    int f=a.size()%2;
    int sum=0;

        for(int i=0;i<a.size()/2;i++){
            if(a[i]!=a[a.size()-i-1])sum++;
        }
   cout<<sum;
   return 0;
}
