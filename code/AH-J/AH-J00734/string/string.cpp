#include<bits/stdc++.h>
using namespace std;
int main(){
    frepoen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string l1[100000000] ,l2[100000000],ln[200000010];
    string s;
    int a,sum = 0,c,ans;
    cin>>a;
    for(int i = 0;i< a;i++){
        cin>>c>>s;
        for(int j = 0;j<c;j++){
            ln[i] = s;
            ans++;
        }
    }

    for(int i = 0;i<ans/2;i++){
        l1[i] = ln[i];
    }
    for(int i = ans- 1;i> ans/2;i--){
        l2[i] = ln[i];
    }
    for(int i = 0;i<ans/2;i++){
        if(l1[i] != l2[i])sum++;
    }
    cout<<sum;

    return 0;
}


