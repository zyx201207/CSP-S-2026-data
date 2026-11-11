#include <bits/stdc++.h>
using namespace std;

int a[200005];
char c[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int x=1,y=n;
	long long sum=0;
	while(x<y){
		if(c[x]==c[y]){
			if(a[y]>a[x]){
				a[y]-=a[x];
				x++;
			}else if(a[x]>a[y]){
				a[x]-=a[y];
				y--;
			}else{
				x++;
				y--;
			}
		}else{
			if(a[y]>a[x]){
				sum+=a[x];
				a[y]-=a[x];
				x++;
			}else if(a[x]>a[y]){
				sum+=a[y];
				a[x]-=a[y];
				y--;
			}else{
				sum+=a[y];
				x++;
				y--;
			}
		}
	}
	cout<<sum;
	return 0;
}
