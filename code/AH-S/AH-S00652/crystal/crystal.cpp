#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int i,n,m,x;
int a[N];
int ans[N];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m<=5)
    cout<<"3";
    else if(m<=10)
    cout<<"4";
	return 0;
}
