#include<bits/stdc++.h>
using namespace std;
int a[200000];
long long pj=1;
int n;
int m;
bool f=1;
bool f2=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pj*=2;
		if(a[i]!=i-1) f2=0;
		if(pj-1!=a[i]) f=0;
	}sort(a+1,a+n+1);
	if(f2){
		cout<<a[n-m+1];
		//0010 0011
	}else if(f){
		cout<<a[n-m+1];//0 1 2 3 4 5 6 7 8 9 0
	}else if(m==1){
		cout<<a[n];
	}else if(m==2){
		int ma=-2147483638;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i] & a[j])>ma){
					ma=(a[i] & a[j]);
				}
			}
		}cout<<ma;
	}else if(m==n-1){
		int g1=a[n-1],g2=a[n];
		for(int i=n-1;i>=1;i--){
			g1=(g1 & a[i]);
		}for(int i=n;i>=2;i--){
			g2=(g2 & a[i]);
		}cout<<max(g2,g1);
	}else if(m==n){
		int g=a[n];
		for(int i=n-1;i>=1;i--){
			g=(g & a[i]);
		}cout<<g;
	}
	return 0;
}
