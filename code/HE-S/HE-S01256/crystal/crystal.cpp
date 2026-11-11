#include <bits/stdc++.h>
using namespace std;
int main{
//    freopen("crystal.in","r",stdin)
//    freopen("crystal.out","w",stdout)
    int n,m,ans=0,s=0;
    cin>>n>>m;
    int a[n];
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans=i*(a[i+1]-a[i])
		if(m>ans){
			m-=ans;
			a[i]+=a[i+1]-a[i];
			s++;
		}
	}
    cout<<s;
    return 0;
} 
