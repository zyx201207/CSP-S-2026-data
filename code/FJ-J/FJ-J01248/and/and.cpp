#include <bits/stdc++.h>
using namespace std;

long long a[2000005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >>n>>m;
	long long maxx=INT_MIN;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		if(m==1){
		maxx=max(maxx,a[i]);			
		}
	}
	long long ans=a[1];
	for(int i=2;i<=n;i++){
		ans=ans&a[i];
	}
	if(m==1){
		cout <<maxx;
		return 0;
	}
	if(m==n){
		cout <<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					long long c=a[i]&a[j];
				    maxx=max(maxx,c);
				}
			}
		}
		cout <<maxx;
		return 0;
	}
	return 0;
}
