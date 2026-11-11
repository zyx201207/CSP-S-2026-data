#include<bits/stdc++.h>
using namespace std;
int n,m=0,k,ans=0;
char a[200005],c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k>>c;
		for(int i=m+1;i<=m+k;i++)a[i]=c;
		m+=k;
	}
	for(int i=1;i<=m/2;i++){
		if(a[i]!=a[m-i+1]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	//ys uid:230118859
	return 0;
}
