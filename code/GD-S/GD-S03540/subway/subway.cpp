#include<bits/stdc++.h>
using namespace std;
int r,l;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,mid=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		mid++;
		cin>>r>>l;
		if(m>=n){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout<<r<<endl<<l;
	
	return 0;
}
