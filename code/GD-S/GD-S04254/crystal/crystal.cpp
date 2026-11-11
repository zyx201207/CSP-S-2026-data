#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[100000005],cnt=0,cntn=0,maxn=10000000,maxi=-1;
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	int cmpm=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt++;
	}
	sort(a+1,a+1+n);
	int ans=cnt/2+1;
	for(int i=ans+1;i<=cnt;i++){
		if(a[i]==a[ans]){
			ans++;
			cntn++;
		}
	}
	for(int i=ans;i>0;i--){
		if(m>=0){
			m-=a[ans]-a[i];
			cntn++;
		}
		
	}
	while(m>=0){
		if(m>=0){
			ans++;
			cntn=0;
			m=cmpm;
			for(int i=ans;i>0;i--){
				if(m>=0){
					m-=a[ans]-a[i];
					cntn++;
				}
			}
		}
	}
	if(m<=0){
		m=cmpm;
		cntn=0;
		ans-=1;
		for(int i=ans;i>0;i--){
		if(m>=0){
			m=m-(a[ans]-a[i]);
			cntn++;
		}
	}
	}
	cout<<cntn;
	return 0;
} 
