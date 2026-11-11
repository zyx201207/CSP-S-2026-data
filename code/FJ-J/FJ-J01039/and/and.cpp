#include<bits/stdc++.h>
using namespace std;
long long rjz[40],a[200005],fz,s=(1<<31)-1;
int n,m,f[200005][40],b[200005],s1,pd,dq,sl;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		fz=a[i];
		for(int j=1;j<=31;j++){
			if(fz%2==1){
				f[i][j]=1;
			}
			fz/=2;
		}
	}
	for(int j=31;j>=1;j--){
		s1=0;
		for(int i=1;i<=n;i++){
			if(f[i][j]==1&&b[i]==dq){
				s1++;
			}
		}
		if(s1>=m){
			for(int i=1;i<=n;i++){
				if(f[i][j]==1&&b[i]==dq){
					b[i]++;
				}
			}
			dq++;
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]==dq){
			sl++;
			if(sl<=m){
				s&=a[i];
			}
		}
	}
	cout<<s;
	return 0;
}
/*
*/
