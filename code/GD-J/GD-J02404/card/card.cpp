#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500500],b[300300];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		
		b[a[i]]+=(rand()%3+1);
		if(i+1==n){
			b[a[i]]=n;
		}
	}

	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
}
