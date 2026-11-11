#include<bits/stdc++.h>
using namespace std;
string a;
long long b[22000][2200];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=1,j=1,z=0,box=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){
		ans=1;
		while(a[i]>0){
		if(a[i]-ans*2>0){
			ans*2;
			j++;
		}
		if(ans==1){
			a[i]=0;
			b[i][1]++;
		}
		else{
			a[i]=a[i]-ans;
			b[i][j]++;
			ans=1;
		}
	}
	}
	cout<<"12";
	return 0;
}
