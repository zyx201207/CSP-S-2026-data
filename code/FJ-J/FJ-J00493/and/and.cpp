#include<bits/stdc++.h>
using namespace std;
const int MAX=2e5+2;
int a[MAX],max1;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+1+n,greater<int>());
		cout<<a[1];
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int c=a[i]&a[j];
			    max1=max(max1,c);	
			}
		}
		cout<<max1;
	}
	return 0;
}
