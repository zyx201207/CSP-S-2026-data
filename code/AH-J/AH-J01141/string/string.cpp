#include<bits/stdc++.h>
using namespace std;
int n,g=1,ans;
unsigned int a[100000010],d[100000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int k;
		char c;
		cin>>k>>c;
		int f=c-'a'+1;
		d[g]+=f,d[g+k]-=f; 
		g+=k;
	}
	for(int i=1;i<g;i++)
		a[i]=a[i-1]+d[i];
	int i=1,j=g-1;
	while(i<=j){
		if(a[i]!=a[j])	ans++;
		i++,j--;
	} 
	cout<<ans;
	return 0;
}
