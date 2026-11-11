#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int a,b;
    cin>>a>>b;
    int m[1000001]={0};
    for(int i=1;i<=a;i++){
        cin>>m[i];
    }
    sort(m,m+a+1);
    cout<<m[a-b+1];
    return 0;
}
