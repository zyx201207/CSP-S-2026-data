#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
int a[200005];
string c[200005];
string d[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<"0";
		return 0; 
	}
	if(n==2){
		if(c[1]==c[2]){
			cout<<"0";
			return 0;
		}
		else{
			cout<<max(a[1],a[2]-min(a[1],a[2]));
			return 0;
		}
	}
	int sum=0;
	if(n<=10){
		
		for(int i=1;i<=n;i++){
			while(a[i]--){
				d[sum++]=c[i];
			}
		}
		for(int i=1;i<=(sum+1)/2;i++){
			if(c[i]!=c[sum]){
				ans++;
				sum--;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=(n+1)/2;i++){
		if(a[i]==a[n]&&c[i]!=c[n]){
			ans+=a[i];
		}
		else {
			ans+=max(a[i],a[n])-min(a[i],a[n]);
			if(a[i]<a[n]&&c[i+1]!=c[n]){
				a[i+1]=a[i+1]-a[n]-a[i];

			}
			if(a[i]>a[n]&&c[n-1]!=c[i]){
				a[n-1]=a[n-1]-a[i]-a[n];

			}
		}
		n--;
	}
	cout<<ans;
	return 0;
}
