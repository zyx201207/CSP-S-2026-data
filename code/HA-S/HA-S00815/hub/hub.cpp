#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int x1[2000005],x2[2000005];
bool f1=true;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,k,m;
		cin>>n>>k;
		m=n;
		while(n--){
			cin>>x1[n]>>x2[n];
		}
		long long q=(m+1)/8;
		int s=q%1000;
		cout<<q-(s/2)+1;
	}
	return 0;
}
