#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long n,m,x[N],z[N],num_xiabiao = 1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>m>>n;
    x[0] = 1;
    x[1] = 2;
    for(int i = 2;i <= n+1;i++)
        x[i] = x[i-1]+x[i-2];
    for(int i = 1;i <= n+1;i++){
        for(int j = 0;j < x[i];j++)
            z[num_xiabiao++] = i+1;
    }
    cout<<z[n];
	return 0;
}
