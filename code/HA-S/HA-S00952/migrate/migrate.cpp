#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	long long c,t;
	cin>>c;
	cin>>t;
	while(t--){
		long long n,d,cnt=0,sum=0;
		cin>>n>>d;
		long long a[n+1];
		if(n<=3){
			cout<<0;
		}
		else{
			cin>>a[0]>>a[1]>>a[2];
			for(long long i=3;i<n;i++){
				cin>>a[i];
				if(a[i]-a[i-3]>d&&a[i]-a[i-2]<=d&&a[i-1]-a[i-3]<=d){
					cnt++;
				}
			}	
		}
//		if(n>2){
//			int k=a[n-1]-a[n-2];
//			if(k<=d/2&&k>d/3){
//				cout<<n-4<<'/n';
//			}
//			else{
//				cout<<0<<'/n'
//			}
//		}
//		else{
//			cout<<0;
//		}
//	}
	cout<<cnt<<endl;
	}
	return 0;
}
