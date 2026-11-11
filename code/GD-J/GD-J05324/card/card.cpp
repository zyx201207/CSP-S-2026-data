#include<bits/stdc++.h>
using namespace std;
int a[1221443],asd[2942977],a2[439829];
int a1[3949923];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n,m,ji=0;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		a2[a[i]]=1;
	}
	ji=n;
	long long kp=1;
	while(ji>=1) {
		for(int i=1; i<=ji; i++) {
			if(a2[a[i]]==1) {
				a1[kp++]=a[i];
				if(asd[a[i]]==1) {
					for(int j=i; i<=ji; j++) {
						a2[a[j]]=0;
						ji--;
						asd[j]=0;
					}
				}
			}
		}
		kp++;
		if(a2[m]==1){
			cout<<kp;
		}
	}
	return 0;
}
