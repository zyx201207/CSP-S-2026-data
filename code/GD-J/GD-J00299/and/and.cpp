#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200001];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}else if(m==1){
		int max=-1;
		for(int i=1;i<=n;i++){
			if(a[i]>max)max=a[i];
		}
		cout<<max;
		return 0;
	}else if(m==2){
		int max=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]&a[j]>max)max=a[i]&a[j];
			}
		}
		cout<<max;
		return 0;
	}
	return 0;
}
