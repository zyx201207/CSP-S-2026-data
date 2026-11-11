#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ma=0;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
			cin>>a[i];
			if(a[i]>ma){
				ma=a[i];
			}
		}
	if(m==1){
		cout<<ma;
	}else if(m==2){
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				if(a[i]&a[j]>ma){
					ma=i;
				}
			}
		}
	}
	cout<<ma;
	return 0;
}

