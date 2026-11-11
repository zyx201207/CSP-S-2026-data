//张俊杰 遵义市第二十一中学  GZ-S00030
#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[500001];
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	int tmp=n/2+1,sum=0;
	for(int i=1; i<=n; i++) {
		if(a[tmp]-a[i]>=0) {
			m-=a[tmp]-a[i];
			sum++;
		} else {
			continue;
		}
	}
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
