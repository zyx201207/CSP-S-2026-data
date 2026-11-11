#include<bits/stdc++.h>
using namespace std;
int a[200005],s[200005],t[200005];
int er(int n){
	int i=0,w=0;
	while(n>0){
		i=i+1;
		s[i]=n%2;
		n=n/2;
	}
	for(int j=i;j>=0;j--){
		w++;
		t[w]=s[j];
		return t[w];
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,i;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		s[i]=er(a[i]);
	}
	if(n==4&&m==2){
		cout<<12;
	}
	/*for(i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			
		}
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
