#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int max=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=max){
				max=a[i];
			}
		}
		cout<<max<<endl;
		return 0;
	}
	if(m==2){
		cout<<a[n]<<endl;
		return 0;
	}
	cout<<a[n]<<endl;
	return 0;
}
