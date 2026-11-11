#include<bits/stdc++.h>
using namespace std;
int l[900005],a[900005];
long long ans=0;
long long sum=0,o=0;
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	sort(l+1,l+n+1);
	
	for(int i=1;i<=n;i++){
		//cout<<"i="<<i<<endl;
		for(int j=1;j<=n;j++){
		//	cout<<"j="<<j<<endl;
			if(l[i]==l[j]&&ans!=0){
				a[i]=ans+1;
				//cout<<"a[i]="<<a[i]<<endl;
				if(a[i]==a[i-1]){
					o++;	
				}
				if(sum>m){
					cout<<a[i-1]+o;
					return 0;
				}
				ans=0;
				sum=0;
				break;
			}
			else if(l[i]!=l[j]){
				sum=sum+(l[i]-l[j]);
				ans++;
				//cout<<"sum="<<sum<<endl<<"ans="<<ans<<endl;
			} 
		} 
	}
	if(ans==0){
		cout<<n;
	}
//	for(int i=0;i<n;i++){
//		cout<<l[i];
//	}
	return 0;
} 
