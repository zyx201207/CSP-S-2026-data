#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ad;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int o=1;
	ad=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(1){
		int h=a[o],m1=m;
		for(int i=1;i<=n;i++){
			if(i!=o){
				ad=max(ad,a[o]&a[i]);
			}
		}
		o++;
		if(o>n){
			break;
		}
	}
	cout<<ad;
	return 0;
}


