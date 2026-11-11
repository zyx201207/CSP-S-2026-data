#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(n==1)cout<<a[i];		
	}	
	if(n==2){
		if(m==1){
			cout<<max(a[1],a[2]);
		}
		else{
			cout<<a[1]&&a[2];
		}
	}
	fclose(stdin);
    fclose(stdout);
} 
