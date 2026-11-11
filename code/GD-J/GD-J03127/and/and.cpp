#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a[200005];
	int n,m,ma=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>ma){
			ma=a[i];
		}
	}
	cout<<rand()%ma;
	return 0;
}
