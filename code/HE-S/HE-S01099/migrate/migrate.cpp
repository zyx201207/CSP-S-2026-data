#include <bits/stdc++.h>
using namespace std;
long long c,t;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d,a[9999],b[9999],ddd=0;
		cin>>n>>d;
		for (int i=0 ; i<n ; i++)cin>>a[i];
		for (int i=0 ; i<n ; i++){
			int num=0;
			for (int j=i+1 ; j<n-1 ; j++){
				if (a[i]+d>=a[j])num++;
			}
			if (num==2)ddd++;
		}
		cout<<ddd<<endl;
	}
	
	
	
	
	return 0;
}
