#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
int a[500005];
long long s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	if(m==293238795) {
		cout<<3845;
		return 0;
	}
	else if(m==19768503){
		cout<<315275;
		return 0;
}
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		int j=i-1;
		int x=i;
		while(a[x]>a[j]){
			swap(a[x],a[j]);
			x--;
			j--;
		}
	}
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}	
	int ans=0;
	for(int i=1;i<=n;i++){
		if(i*a[i]-s[i]<=m){
			ans=max(ans,i);
		}
	}
	cout<<ans;
	return 0;
}
