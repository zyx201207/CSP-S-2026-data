#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int mid=n/2+1;
	int mida=a[mid];
	int i=1;
	while(m>0 &i<mid){
		if(m-(a[mid]-a[mid-i])>=0){
			m-=(a[mid]-a[mid-i]);
		}else{
			break;
		}
		ans++;
		i++;
	}
	i=1;
	while(a[mid+i]==a[mid]){
		ans++;
		i++;
	}
	cout<<ans+1;
	return 0;
}


























/*L O V E Ü¿¹âPriseTwinkle
        _      _
	   / \    / \
	  /   \  /   \
	 /     \/     \
	 \            /
	  \   Ü¿¹â   /
	   \        /
	    \      /
	     \    /
	      \  /
	       \/
