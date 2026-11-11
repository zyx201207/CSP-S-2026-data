#include <bits/stdc++.h>
using namespace std;
int a[5000005],b[5000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a,a+1);
	int z;
	if(n%2==0) z=n/2;
	else z=(n+1)/2;
	for(int i=1;i<=n;i++){
		if(a[i]>=a[z]) b[a[i]-a[z]]+=1;
		else b[a[z]-a[i]]+=1;
	}
	int s=0,sf=0,j=0;
	while(sf<=m){
		for(int i=0;i<b[j];i++){
			sf+=j;
			s+=1;
			if(sf>m){
				s=s-1;
				break;
			}
		}
		j++;
	}
	cout << s;
	return 0;
}
