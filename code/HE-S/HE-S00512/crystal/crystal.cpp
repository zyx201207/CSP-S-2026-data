#include<bits/stdc++.h>
using namespace std;
int a[500200];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int cnt=1;
	int x;
	if(n%2==0){
		x=a[n/2];
		for(int i=1;i<n/2-1;i++){
			if(a[i]+a[i+1]+m==2*x){
				cnt+=2;
			}
			else if(a[i]+m==x){
				cnt++;
			}
			else if(a[i]==x){
				cnt++;
			}
		}
		for(int i=n/2+1;i<=n;i++){
			if(a[i]==x){
				cnt++;
			}
		}
	}
	else{
		x=a[n/2+1];
		for(int i=1;i<n/2;i++){
			if(a[i]+a[i+1]+m==2*x){
				cnt+=2;
			}
			else if(a[i]+m==x){
				cnt++;
			}
			else if(a[i]==x){
				cnt++;
	        }
		}
		for(int i=n/2+2;i<=n;i++){
			if(a[i]==x){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
