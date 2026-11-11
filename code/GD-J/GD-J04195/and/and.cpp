#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010];
long long aa[100010],d=0,w=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int ii=0,b=a[i], bb[100010];
		while(b){
			ii++;
			bb[ii]=b%2;
			b/=2;
		}
		for(int j=ii;j>0;j--){
			aa[i]*=10;
			aa[i]+=bb[j];
		}
		if(aa[i]>d) d=aa[i],w=i;
	}
	int s=0;
	if(m==1){
		cout<<a[w];
	}else cout<<a[w];
	return 0;
}
