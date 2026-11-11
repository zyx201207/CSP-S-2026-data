#include<bits/stdc++.h>
using namespace std;
long long s[1000001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	long long max1=-1;
	if(m==n){
		max1=s[1];
		for(int i=2;i<=n;i++){
			max1=max1&s[i];
		}
		cout<<max1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			max1=max(max1,s[i]&s[j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			long long k=s[i]&s[j];
			if(max1==k){
				s[i]=-1;
				s[j]=-1;
				break;
			}
		}
	}
	m-=2;
	while(m--){
		long long max2=-1;
		for(int i=1;i<=n;i++){
			if(s[i]!=-1){
				max2=max(max2,max1&s[i]);
			}
		}
		for(int i=1;i<=n;i++){
			if(s[i]==-1){
				continue;
			}
			long long k=s[i]&max1;
			if(k==max2){
				max1=max1&s[i];
				s[i]=-1;
				break;
			}
		}
	}
	cout<<max1;
	return 0;
}
