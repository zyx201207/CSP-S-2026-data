#include<bits/stdc++.h>
using namespace std;
struct s{
	int n;
	char c;
} a[200026];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>a[i].n>>a[i].c;
	}
	int i=1,j=n;
	long long ans=0;
	
	while(j>i){
		int minn=min(a[i].n,a[j].n);
		if(a[i].c!=a[j].c) ans+=minn;
		a[i].n-=minn;
		a[j].n-=minn;
		if(a[i].n==0) i++;
		if(a[j].n==0) j--;
	}
	cout<<ans<<"\n";
}
