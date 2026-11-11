#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],lji=0,rji=0,cha[500005]={},ned[500005]={},rig=0,lef=0,l=0,r,minn=1e9,maxx=-1e9;
/*int check(int x,int q){
	int cont=0;
	cout<<q;
	for(int i=1;i<=n;i++){
		q=m;
		cont=0;
		rig=i+1;
		lef=i-1;
		while(q>=0){
		//	cout<<q;
			if(cha[rig]>=cha[lef]&&lef>=2){
				lef--;
				q-=cha[lef+1];
				cout<<q;
				cont++;
			}else if(cha[rig]<=cha[lef]&&rig<=n){
				rig++;
				cont++;
				cout<<q;
				q-=cha[rig-1];
			}
			if(lef<=2&&rig>=n) break;
		//	cout<<q;
		}
		if(cont>=x){
			return 1;
		}else{
			return 0;
		}
	}
}*/ 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(minn,a[i]);
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		cha[i]=a[i]-a[i-1];
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		ned[i]=ned[i-1];
		if(i%2==1){
			sum+=cha[2];
			ned[i]+=sum;
		}else{
			ned[i]+=sum;
		}
	//	cout<<ned[i]<<" ";
	}
	for(int i=1;i<=n;i++){
		if(m<ned[i]){
			cout<<i;
			return 0;
		} 
	}
	cout<<n;
	//30+0+0+0=30 niceeeeeeeeeeeeeeeeeeee
	
} 
