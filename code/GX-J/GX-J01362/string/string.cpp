#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n,i=0,j=0,count=0,x=0;
    vector<long long> a(n);
    string c,temp,temp2;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    for(i=0;i<n;i++){
        for(j=0;j<a[i];j++){
            temp+=c[i];
        }
    }

    for(i=temp.size()-1;i>=0;i--){
        temp2[i-i+x]=temp[i];
        x++;
    }
    for(i=0;i<temp2.size();i++){
        cout<<temp2[i];
    }
    if(temp==temp2){
        cout<<count;
    }
    return 0;
}

