#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50005],b[50005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int op=0,k=0,oop=0,kk=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		k=a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(a[i]==k){
			op++;
		}
	}
	for(int i=0;i<n-1;i++){
		b[i]=a[i+1]-a[i];
		kk=b[i];
	}
	for(int i=0;i<n;i++){
		if(b[i]==kk){
			oop++;
		}
	}
	if(oop==n-1){
		cout<<m/kk;
		return 0;
	}
	if(op==n){
		cout<<n;
		return 0;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		int s=m;
		int b[500005]={0};
		int xzb=0;
		for(int j=0;j<n;j++){
			if(i!=j){
				b[xzb]=abs(a[i]-a[j]);	
				xzb++;
			}
		}
		int zb=0;
		sort(b,b+xzb);
		while(s>=0&&zb!=xzb){
			s-=b[zb];
			zb++;
		}
		ans=max(ans,zb);
	}
	cout<<ans;
	return 0;
}
