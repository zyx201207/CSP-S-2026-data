#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,pd[100009],wz[100009],ans[100009],cs[100009];
int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
    	cin>>pd[i];
    	cs[pd[i]]++;
    	wz[pd[i]]=i;
	}
	for(int i=1;i<=m;i++){
	    cout<<n;
	}
	return 0;
}
