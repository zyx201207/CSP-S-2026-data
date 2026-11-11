#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[100005],b[100005],max;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cout<<a[i];
		for(int i=1;i<=m;i++){
			for(int p;p<=n;){
				p^=p;
				b[i]=p;
			}
		}
	}
	max=b[1];
	for(int i=1;i<=n;i++){
		if(b[i]>max)max=b[i];
	}
	cout<<max;
	return 0;
}
