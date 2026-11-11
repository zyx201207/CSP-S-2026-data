#include<bits/stdc++.h>
using namespace std;
vector<char>x;
int a,a1,x1,x2,ans=0;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>a;
    for (int i=i;i<=a;i++){
        cin>>a1>>c;
        for (int j=1;j<=a1;j++){
            x.push_back(c);
        }
    }
    x1=0;
    x2=x.size()-1;
    for (x1;x1<=x.size()/2+1;x1++){
        if(x[x1]!=x[--x2]){
            ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}