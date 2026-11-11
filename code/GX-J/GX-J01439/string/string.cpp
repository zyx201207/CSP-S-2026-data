
#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string str;
    for(int i=0;i<n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=0;j<a;j++){
            str+=c;
        }
    }
    int sum=0;
    string hui;
    for(int i=0;i<str.size()/2;i++){
        hui+=str[i];
    }
    hui+=str[str.size()/2+str.size()%2-1];
    for(int i=0;i<str.size()/2;i++){
        hui+=str[i];
    }
    for(int i=0;i<str.size();i++){
        if(str[i]!=hui[i]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
