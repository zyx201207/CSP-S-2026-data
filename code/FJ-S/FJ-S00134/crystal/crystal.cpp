#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			if(a[j]<a[j-1]){
				int x=a[j];
				a[j]=a[j-1];
				a[j-1]=x;
			}
		}
	}
	int a_a=0;
	for(int i=0;i<n;i++){
		if(a[i]==i+1){
			a_a++;
		}
	}
	if(a_a==n){
		cout<<int(sqrt(2*m));
		return 0;
	}
	int b_b=a[1]-a[0];
	int bb=0;
	for(int i=1;i<n;i++){
		if(a[i]-a[i-1]==b_b){
			bb++;
		}
	}
	if(bb==n-1){
		cout<<int(sqrt(2*m/b_b));
		return 0;
	}
	for(int i=0;i<n;i++){
		int numm=0;
		int cnt=1;
		for(int j=i-1;j>=0;j--){
			numm+=a[i]-a[j];
			if(numm>m){
				break;
			}
			cnt++;
		}
		//cout<<cnt<<" ";
		ans=max(cnt,ans);
	}
	cout<<ans;
	return 0;	
} 
