#include<bits/stdc++.h>
using namespace std;
int a[200000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,x;
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=1;
	for(int i=1;i<=x;i++){
		int MAX=-1;
		for(int i=1;i<=n;i++){
			if(a[i]>MAX){
				MAX=a[i];
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==MAX){
				a[i]=0;
				break;
			}
		}
		ans&=MAX;	
	}
	cout<<ans;
	return 0;
}
