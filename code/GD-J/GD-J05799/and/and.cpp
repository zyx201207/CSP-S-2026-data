#include<bits/stdc++.h>
using namespace std;
int x[1000005];
int y[1000005];
int z[2000010];
int a[1000005];
int b[1000005];
int id;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ma1=-1,ma2=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(ma1<a[i]){
			ma1=a[i];
			id=i;
		}
	}
	b[id]=1;
	while(m--){
		for(int i=1;i<=n;i++){
			if(a[i]>ma2&&b[i]!=1){
			ma2=a[i];
			id=i;
			}
		}
	}

	ma1=0;
	for(int i<z.size()-1;i>=0;i--){
		int d=2;
		while(i--){
			d*=2;
		}
	}
	return 0;
}
