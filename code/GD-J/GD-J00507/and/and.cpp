#include <iostream>
using namespace std;
int n,m;
int a[200005]={};
bool used[200005]={};
int d(int cnt){
	int mx=-1;
	if(cnt==1)return a[0];
	if(cnt==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(mx<a[i]&a[j]&&(!used[i])&&(!used[j])){
					mx=a[i]&a[j];
					used[i]=true;
					used[j]=true;
				}
			}
		}
	return mx;
	}
	for(int i=1;i<=n;i++){
		if(mx<d(cnt-1)&a[i]&&(!used[i])){
			mx=d(cnt-1)&a[i];
			used[i]=true;
		}	
	}
	return mx&d(cnt-1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
		cout<<d(m);
	return 0;
}
