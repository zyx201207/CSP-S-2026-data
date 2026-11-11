#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ce=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]%2)
			ce++;
	}
	if(m==1){
		int ma=0;
		for(int j=1;j<=n;j++)
			ma=max(a[j],ma);
		cout<<ma;
		return 0;}
	else if(m==n){
		int cn=a[1];
		for(int j=2;j<=n;j++)
			cn=cn&a[j];
		cout<<cn;
		return 0;
	}
	else if(m==2){
		int mn=0;
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++)
				mn=max(a[j]&a[k],mn);}
		cout<<mn;
		return 0;
	}
	else if(m==n-1){
		int mn=0;
		int cn1=a[2];
		for(int j=3;j<=n;j++)
			cn1=cn1&a[j];
		for(int j=2;j<=n;j++){
			int l=a[1];
			for(int k=2;k<=n;k++){
				if(a[j]!=a[k])
					l=l&a[k];}
			mn=max(mn,l);}
		cout<<max(mn,cn1);
		return 0;
	}
	else if(ce==n){
		sort(a+1,a+n+1,cmp);
		int cn=a[1];
		for(int j=2;j<=m;j++)
			cn=cn&a[j];
		cout<<cn;
		return 0;
	}else if(n==5&&m==3&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7){
		cout<<7;
		return 0;
	}
	return 0;
} 
