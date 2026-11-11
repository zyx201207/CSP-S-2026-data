#include <bits/stdc++.h>
using namespace std;
int n,ans=1;
long long a[500002];
long long m;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int tot=0; 
	int tot2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i) tot++;
	}
	if(m==0){//m==0特判 O(2n+logn)
		long long tqc[500002];
		for(int i=1;i<=n;i++){
			tqc[a[i]]++;
		}
		sort(tqc+1,tqc+1+n);
		cout<<tqc[n];
		return 0;
	} 
	for(int i=1;i<n-1;i++){ 
		if(a[i+1]-a[i]==a[i+2]-a[i+1]) tot2++;
	}
	if(tot2==n-2 && a[n]-a[n-1]==a[2]-a[1]) tot2+=2;//特判 
	//等差数列特判 O(2n) 
	if(tot2==n){
		int c=a[2]-a[1];
		int i=1;
		while(m>=c){
			m-=c+c*i;
			i++;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	if(tot==n){//a[i]=i特判 O(2n) 
		int i=1;
		while(m>0){
			m-=i;
			i++;
			ans++;
		}	
		cout<<ans;
		return 0;
	}
	//暴力 O(n^2+logn) 
	int mans=0;
	sort(a+1,a+1+n);
	for(int r=1;r<=n;r++){
		int tem=m;
		mans=0;
		for(int l=1;l<=r;l++){
			if(tem<0) break;
			if(a[r]-a[l]>tem) continue;
			else tem-=a[r]-a[l];
			mans++;
		}
		ans=max(ans,mans);
	}
	cout<<ans;
	return 0;
}
