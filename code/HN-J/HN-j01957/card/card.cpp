#include <bits/stdc++.h>
using namespace std;
const int MAXX=5e5+5;
int a[MAXX],B[MAXX],C[MAXX],cnt[MAXX]={1};
string b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		B[i]=a[i];
		C[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		if(b[a[i]]==0){
			b[a[i]]=1;
			b+=(a[i]+'0');
			for(int j=1;j<=i;j++) cnt[j]++;
		}else{
			for(int j=a[i];j<i;j++){
				b[j]=0;
			}
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		if(a[i]==a[i+1]) B[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(B[i]!=0){
			cout<<cnt[i]<<' ';
		}
	}
	return 0;	
}
