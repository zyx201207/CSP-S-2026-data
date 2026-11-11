#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,a[100005],mx;
	cin>>n;
	for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	for(int i=2;i<=n;i++){
			if(mx<a[i]){
				mx=a[i];
				}
			
		}
		cout<<mx;
		return 0;
}
