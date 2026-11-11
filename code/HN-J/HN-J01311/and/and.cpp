#include<bits/stdc++.h>
using namespace std;
long long n,m,x,maxx;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<+n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(m==2){
				x=a[i]&a[j];
				maxx=max(maxx,x);
			}else{
				for(int k=2;k<=m;k++){
					x=a[i]&a[j]&a[j+1];
					maxx=max(maxx,x); 
				}
			}
		}
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
