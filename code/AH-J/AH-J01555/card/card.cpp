#include <iostream>
using namespace std;
int a[500010],f[300010];
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int flag=1;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) flag=0;
		f[a[i]]++;
	}
	if(flag==1){
		f[0]=0;
		for(int i=1;i<=m;i++){
			f[i]+=f[i-1];
			cout<<f[i]<<" ";
		}
	}
	
	return 0;
}
