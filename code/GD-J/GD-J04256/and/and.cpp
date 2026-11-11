#include<iostream>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,a[200001]={},m;
	cin>>n>>m;
	int maxn=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		int ans=a[0];
		for(int i=1;i<n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
