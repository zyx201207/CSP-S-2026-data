#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(nullptr);
	cin.tie(false);
	long long n;
	cin>>n;
	vector<long long> a(n,0);
	vector<char> b(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	long long ans=0;
	int j=n-1;
	for(int i=0;i<j;i++){
		if(b[i]!=b[j]){
			if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				j--;
				i--;
			}
			
			if(a[i]==a[j]){
				ans+=a[j];
				j--;
			}
			
			if(a[i]<a[j]){
				ans+=a[i];
				a[j]-=a[i];
			}
		}
		else if(b[i]==b[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}
			
			if(a[i]==a[j]){
				j--;
			}
			
			if(a[i]<a[j]){
				a[j]-=a[i];
			}
		}
	}
	
	cout<<ans;
	return 0;
}
