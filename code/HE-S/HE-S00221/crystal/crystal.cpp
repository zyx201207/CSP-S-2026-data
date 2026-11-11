#include<iostream>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
	cin>>a[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]+1==a[i]){
			    a[j]+=1;
			}else if(a[i]+1==a[j]){
			    a[i]+=1;
			}
		}
	}
	int cnt=0;
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
			    cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
