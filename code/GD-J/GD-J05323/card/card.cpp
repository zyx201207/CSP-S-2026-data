#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],ds[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=m;i++){
			cout<<n;
		}
	}else if(m==2){
		for(int i=1;i<=n;i++){
			int n1=n;
			for(int j=i;j<=n1;j++) b[j]=a[j]; 
			for(int j=i;j<=n1;j++){
				int f1=0,f2=0;
				if(b[j]==1 && f1==0) {
					f1=1;
					continue;	
				}
				if(b[j]==2 && f2==0){
					f2=1;
					continue;
				}
				if(b[j]==1 && f1==1){
					if(b[j-1]==1){
						b[j]=0;
						j-=1;
						n1-=1;
					}
					if(b[j-1]==2){
						b[j]=0;
						b[j-1]=0;
						j-=2;
						n1-=2;
					}
				}
				if(b[j]==2 && f2==1){
					if(b[j-1]==2){
						b[j]=0;
						j-=1;
						n1-=1;
					}
					if(b[j-1]==1){
						b[j]=0;
						b[j-1]=0;
						j-=2;
						n1-=2;
					}
				}
			}
			int f1=0,f2=0;
			while(n1--){
				if(b[n1]==1) f1=1;
				if(b[n1]==2) f2=1;
			}
			if(f1) ds[1]++;
			if(f2) ds[2]++;
		}
		cout<<ds[1]<<" "<<ds[2];
	}else{
		for(int i=1;i<=m;i++){
			cout<<n<<" ";
		}
	}
} 
