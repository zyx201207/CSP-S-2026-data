#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

#define LL long long

const int N=2e6+5;
const int M=5e3+3;

LL c,T,n,d,m,ans,inf=2e18;
LL A[N],B[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	unsigned LL rp=-1;
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>A[i];
		}
		if(n==1){
			cout<<"0\n";continue;
		}
		if(c==11||c==12){//a
			m=d/(A[2]-A[1]);
			if(m<=1)cout<<"0\n";
			else cout<<max(0ll,n+1-m*2)<<'\n';
			continue;
		}
		for(int i=1,j=i;i<=n;i++){
			while(j<=n&&A[j]-A[i]<=d)j++;
			B[i]=j-1;
		}
		if(c==13||c==14){//b
			for(int i=1;i<=n;i++){
				LL j=B[i]-2;
				if(j<i)continue;
				ans+=B[j+1]-B[j];
			}
			cout<<ans<<'\n';
			continue;
		}
		if(c<=10||(c>=15&&c<=18)){//small+c?
			for(int i=1;i<=n;i++){
				LL j=B[i],lj=i,m1=1,m2=1;
				while(j<=n){
					if(j==lj)break;
					if(m2==1){
						if(m1==1&&lj<j-1){
							ans+=B[j-1]-B[j-2];
						}
					}
					else{
						ans+=B[j]-B[j-1];
					}
					if(B[j-2]==B[j-1])m1=2;
					if(B[j-1]==B[j]){
						if(m1>1)break;
						else m1=m2=2;
					}
					if(m2>2)break;
					lj=j;j=B[j];
				}
			}
			cout<<ans<<'\n';
		}
		else{//eps
			for(int i=1;i<=n;i++){
				LL j=B[i],lj=i,m1=1,m2=1;
				while(j<=n){
					if(j==lj)break;
					if(m2==1){
						if(m1==1&&lj<j-1){
							ans+=B[j-1]-B[j-2];
						}
					}
					else{
						ans+=B[j]-B[j-1];
					}
					if(B[j-2]==B[j-1])m1=2;
					if(B[j-1]==B[j]){
						if(m1>1)break;
						else m1=m2=2;
					}
					if(m2>2)break;
					lj=j;j=B[j];
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
