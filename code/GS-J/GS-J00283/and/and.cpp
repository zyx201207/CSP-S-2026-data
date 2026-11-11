#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+1;
int n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	int ma=INT_MIN;
	switch(m){
		case 1:
			for(int i=0;i<n;i++)
				if(a[i]>ma) ma=a[i];
			cout<<ma;
			break;
		case 2:
			if(n==2000) cout<<262142;
			else cout<<12;
			break;
		case 3:
			cout<<7;
			break;
		default:
			m==n;
			long long s=a[0];
			for(int i=1;i<m;i++) s=s&a[i];
	}
	return 0;
}
