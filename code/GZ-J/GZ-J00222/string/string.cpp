//liYangJunYi GZ-J00222
#include<bits/stdc++.h>
using namespace std;
queue<char> s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,k=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=0;i<a;j++) s.push(c);
    }
    while((!s.size()==1)){
        if(!(s.front()==s.back())) k++;
        s.pop();
    }
    cout<<k;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
