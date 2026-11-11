#include<iostream>
using namespace std;

const int N=2*1e5;
int n,m,ans;
int a[N+1]={};

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
