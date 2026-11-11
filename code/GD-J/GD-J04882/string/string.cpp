#include<bits/stdc++.h>
using namespace std;
int a[200005];
string c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long ans=0;
	int x=1,y=n;
	while(x<y){
		if(c[x]==c[y]){
			if(a[x]==a[y]){
				x++;
				y--;
			}
			else if(a[x]>a[y]){
				a[x]-=a[y];
				y--;
			}
			else if(a[x]<a[y]){
				a[y]-=a[x];
				x++;
			}
		}
		else{
			if(a[x]==a[y]){
				ans+=a[x];
				x++;
				y--;
			}
			else if(a[x]>a[y]){
				a[x]-=a[y];
				ans+=a[y];
				y--;
			}
			else if(a[x]<a[y]){
				a[y]-=a[x];
				ans+=a[x];
				x++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
