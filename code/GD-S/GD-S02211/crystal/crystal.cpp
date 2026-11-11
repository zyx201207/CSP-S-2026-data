#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10101020],pj,mxi=0,b[10101020],fl=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int uuu=a[2]-a[1];
	for(int i=1;i<n;i++){
		if(a[i+1]-a[i]!=uuu){
			fl=0;
			break;
		}
	}
	if(fl){
		long long xxt=0,uu=uuu;
		while(m>=0){
			m-=uu;
			uu+=uuu;
			xxt++;
		}
		cout<<min(xxt-1,n);
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long w=n;
		memset(b,0,sizeof(b));
		for(int j=1;j<i;j++){
			b[j]=a[i]-a[j];
			if(b[j]==0){
				break;
			}
		}
		sort(b+1,b+w+1,cmp);
		long long j=0;
		long long ll=m;
		for(;ll-b[j]>=0&&j+1<i;++j){
			ll-=b[j];
		}
		mxi=max(mxi,j+1);
	}
	cout<<mxi;
	return 0;
} 
