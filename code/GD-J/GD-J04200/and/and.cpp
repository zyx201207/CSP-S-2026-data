#include<bits/stdc++.h>
using namespace std;
long long a[210000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int ma=-1,s=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s=min(a[i],a[i-1]);
		if(s>ma){
			ma=s;
		}
	}
	cout<<ma;
	return 0;
}
