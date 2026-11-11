#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,tnt=0;
    cin>>n;
    vector<string> v1;
    for(int i=0;i<n;i++){
        int a;
        string c;
        cin>>a>>c;
        for(int i=1;i<n;i++)
            v1.push_back(c);
    }
    int b=v1.size()-1;
    for(int i=0;i<b/2;i++){
        if(v1[i]!=v1[b-1-i]){
            v1[b-1-i]=v1[i];
            tnt++;
        }
    }
    cout<<tnt<<endl;
    return 0;
}
