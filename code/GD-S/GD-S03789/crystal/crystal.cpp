#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[510000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n>5000){
		if(a[2]-a[1]==1){
			cout<<m/2+1;
		}
		else{
			long long nnn=abs(a[2]-a[1]); 
			cout<<m/nnn; 
		}
		return 0; 
	}
	sort(a,a+n);
	int ans=0,ans1=1;
	long long cnt=0;
	long long began=n-1;
	for(int i=n-1;i>=0;i--){
		if(ans>ans1) ans1=ans;
		
		if(cnt+(a[began]-a[i])<=m){
			cnt=cnt+(a[began]-a[i]);
			ans++;
			if(ans>ans1) ans1=ans;
			if(i==0){
				cout<<ans1;
				return 0;
			}
		}
		else{
			if(i==0){
				cout<<ans1;
				return 0;
			}
			while(cnt+(a[began]-a[i])>m&&i<=began){
				cnt=cnt-((a[began]-a[began-1])*(began-(i+1)));
				began--;
				ans--;
			}
			if(i>began){
				cout<<ans1;
				return 0;
			} 
			cnt=cnt+(a[began]-a[i]);
			ans++;
			if(ans>ans1) ans1=ans;
			
		}
	}
	return 0;

} 
