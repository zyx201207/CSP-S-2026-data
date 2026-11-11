#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	long long a[n+5];
	int b[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=0;
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		cout<<a[i];
//	}
	int lem=m;
	int len=n;
	while(n!=0){
		for(int i=n;i>=1;i--){
			if(a[i]==a[n]){
				b[n]++;
			}
			else if(m>=a[n]-a[i]){
				m-=(a[n]-a[i]);
				b[n]++;
			}
		}
		m=lem;
		n--;
	}
	int before=0;
	for(int i=1;i<=len;i++){
		before=max(before,b[i]);
	}
	cout<<before;
	return 0;
} 
