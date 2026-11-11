#include<bits/stdc++.h>
using namespace std;
int k[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	if(m==1){
		int max=0;
		for(int i=1;i<=n;i++){
			if(k[i]>=max){
				max=k[i];
			}
		}
		cout<<max;
		return 0;
	}
	if(m==2){
		int max=0;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				if((k[i] || k[j])>=max){
					max=(k[i] || k[j]);
				}
			}
		}
		cout<<max;
		return 0;
	}
	if(m==n){
		int max=k[1];
		for(int i=2;i<=n;i++){
			max=max and k[i];
		}
		cout<<max;
		return 0;
	}
	return 0;
}
