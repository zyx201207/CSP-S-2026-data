#include<bits/stdc++.h>
using namespace std;
int n,d,c,t;
int a[1001000],bl[1001000],few[1001000];
long long sum;
int fewlenth(int st,int ed){
	int sums=0;
	int l=0;
	for(int i=st+1;i<=ed;i++){
		l=l+a[i]-a[i-1];
		if(l>d){
			sums+=1;
			l=0;
			i=i-1;
		}
	}
	return sums+1;
}
void fly(int pst,int st,int step){
	int land=st+1;
	if(land>n) return;
	while(a[land]-a[st]<=d&&land<=n){
		if(step+1==fewlenth(pst,land)){
			bl[land]+=1;
		}
		fly(pst,land,step+1);
		land+=1;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ch;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==1) ch=1-a[1];
			a[i]=a[i]+ch;
		}
		for(int i=1;i<=n;i++){
			//cout<<a[i]<<"->"<<n<<":"<<fewlenth(i,n)<<endl;
			for(int j=1;j<=n;j++) bl[j]=0;
			fly(i,i,0);
			for(int j=1;j<=n;j++){
				
				if(bl[j]==2){
					sum+=1;
					//cout<<i<<"-"<<j<<endl;
				}
			}
		}
		cout<<sum;
	}
	return 0;
}
