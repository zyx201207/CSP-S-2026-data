#include<bits/stdc++.h> 
using namespace std;
long long int n,m,a[1000000];
int maxx=0;
int ans[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	ans[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		ans[i]=ans[i-1] & a[i];
	}
	for(int i=1;i<=n-m;i++){
		for(int j=i+1;j<=n;j++){
			if(j-i==m){
				int s=a[j]&ans[i];
				cout<<s<<" ";
				if(s>maxx){
					maxx=s;
				}
			}		
		}	
	}
	cout<<endl;
	cout<<maxx<<endl;
	return 0;
}
