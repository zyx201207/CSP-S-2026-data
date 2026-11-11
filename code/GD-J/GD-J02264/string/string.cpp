#include<bits/stdc++.h>
using namespace std;
int a[1000000],n;
string s;
char m[300000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>m[i];
		
	}
	
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		while(!a[l])l++;
		while(!a[r])r--;
		int minn=min(a[l],a[r]);
		if(m[l]!=m[r])ans+=minn;
		a[l]-=minn;
		a[r]-=minn;
	}
	cout<<ans;
	
	return 0;
} 
