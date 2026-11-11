#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,A,a[N],B;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool C=true;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		A=max(A,a[i]);
		if(i==1){
			B=a[i];
		}else{
			B&=a[i];
		}
		if(a[i]!=i-1){
			C=false;
		}
	}
	if(m==1){
		cout<<A;
		return 0;
	}
	if(m==n){
		cout<<B;
		return 0;
	}
	if(m==2){
		int x=0;
		for(int l=1;l<=n;l++){
			for(int r=l+1;r<=n;r++){
				x=max(x,a[l]&a[r]);
			}
		}
		cout<<x;
		return 0;
	}
	if(m==n-1){
		int ma=0;
		for(int i=1;i<=n;i++){
			ma=max(ma,B|a[i]);
		}
		cout<<ma;
		return 0;
	}
	if(C==true){
		bool f=false;
		for(int i=1;i<=25;i++){
			if(pow(2,i)==n){
				f=true;
				break;
			}
		}
		if(f==true){
			sort(a+1,a+n+1,greater<int>());
			int ans=a[1];
			for(int i=2;i<=m;i++){
				ans&=a[i];
			}
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
