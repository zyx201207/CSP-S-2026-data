#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int l[n+1],ans,k;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	for(int j=1;j<n;j++){
		for(int i=j;i<n;i++){
		if(l[i]>l[j]){
			k=l[i];
			l[i]=l[j];
			l[j]=k;
		}
	}
	}
	
	cout<<l[m-1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
