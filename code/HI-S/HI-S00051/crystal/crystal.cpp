#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n=0,m=0,cnt=0;
	long long list[10005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>list[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int a=abs((list[i+j]-list[i]+m)/2);
			if(m>=a){
				m-=a;
				cnt++;
			}
		}
		
		
			
	}
	
	cout<<cnt-1;
	return 0;
}

