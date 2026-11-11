#include <bits/stdc++.h>
using namespace std;

int max_and[200005],and_[200005];
int main(){
    int n,m,maxx=0;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> and_[i];
        int sum=0;
        for(int j=m;j>=1;j--)
            sum=sum & and_[i-j];
        if(sum>maxx)
            maxx=sum;
        max_and[i]==maxx;
    }
    cout << maxx;
    return 0;
}
