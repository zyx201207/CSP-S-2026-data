#include<bits/stdc++.h>
using namespace std;
long long n,k,a[2000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t!=0){
		t--;
		long long minn=0x7fffffff;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>a[i];
			minn=min(minn,a[i]);
		}
		cout<<minn<<"\n";
	}
	return 0;
}
