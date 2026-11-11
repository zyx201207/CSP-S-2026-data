#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[++n],b[++m],c[m];
	bool r[m];
	for(int i=1;i<n;i++){
		cin>>a[i];
		b[a[i]]=i;
		c[a[i]]=0;
	}
	for(int i=1;i<n;i++){
		for(int j=i;j<n;){
			r[a[j]]=1;
			j=b[a[j]]+1;
		}
		for(int j=1;j<m;j++){
			if(r[j]) c[j]++;
			r[j]=0;
		}
	}
	for(int j=1;j<m;j++){
		cout<<c[j]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
