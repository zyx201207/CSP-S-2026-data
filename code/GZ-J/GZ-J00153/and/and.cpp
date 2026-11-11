//GZ-J00153,遵义市第十九中学,刘婧妍。
#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	if(y>x)return y>x;
	else return x>y;
}
long long a[10000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,mx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1,cmp);
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int r=(i&j);
				if(r>mx)mx=r;
			}
		}
	}else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					int r=(i&j&k);
					if(r>mx)mx=r;
				}
			}
		}
	}else{
		mx=a[1];
		for(int i=2;i<=m;i++){
			mx&=a[i];
		}
	}cout<<mx;
	return 0;
}
