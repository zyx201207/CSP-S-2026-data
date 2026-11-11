#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300005],s[300005];
void f(int x){
	int b[300005][2],o=0;
	for(int i=1;i<=n;i++){
		b[i][0]=0;
	}
	for(int i=x;i<=n;i++){
		if(b[a[i]][0]==0){
			b[a[i]][0]=1;
			b[a[i]][1]=++o;
		}
		else{
			for(int j=1;j<=m;j++){
				if(b[j][0]==1&&b[j][1]>b[a[i]][1]){
					b[j][0]=0;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		s[i]+=b[i][0];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f(i);
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}
