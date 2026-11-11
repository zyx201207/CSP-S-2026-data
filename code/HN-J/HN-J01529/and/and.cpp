#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum=0;
	int a[100005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int t=-1;
		for(int i=1;i<=n;i++)
			t=max(t,a[i]);
		cout<<t;
	}else if(m==n){
		int t=a[1];
		for(int i=2;i<=n;i++)
			t=t^a[i];
		cout<<t;
	}else{
		int t=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				t=max(t,a[i]^a[j]);
			}
		}
		cout<<t;
		
	}
	
	
	
	return 0;
}
