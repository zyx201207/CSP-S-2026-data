#include <bits/stdc++.h> 
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	string a;
	int n,m,o;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
			if(a[i]>a[i-1]){
				o=a[i-1];
				a[i-1]=a[i];
				a[i]=o;
				
			}
			
		
	}			
	cout<<a[m];
	return 0;
	fclose(stdin);
	fclose(stdout);
}
