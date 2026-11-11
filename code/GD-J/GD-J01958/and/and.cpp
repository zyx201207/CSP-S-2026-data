#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long ll;
ll n,m,a[N],ans,sum;
bool cmp(ll s1,ll s2){
	return s1>s2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=10;i++){
		sum=a[i];
		for(int j=i+1;j<=m;j++){
	        while(sum&a[i]<sum&a[j+1]+1){
	    	    j++;
		    }  
		    sum&=a[j];	
	    }
	    ans=max(ans,sum);
	}
	
	cout<<ans;
	return 0;
} 
