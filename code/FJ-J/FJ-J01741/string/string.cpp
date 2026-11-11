#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],cnt,x,y;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	x=1;
	y=n;
	while(1){
		if(x>=y){
			break;
		}
		else if(b[x]==b[y]){
			if(a[x]>a[y]){
				a[x]-=a[y];
				y--;
			}
			else if(a[x]<a[y]){
				a[y]-=a[x];
				x++;
			}
			else{
				x++;
				y--;
			}
		}
		else{
			if(a[x]>a[y]){
				cnt+=a[y];
				a[x]-=a[y];
				y--;
			}
			else if(a[x]<a[y]){
				cnt+=a[x];
				a[y]-=a[x];
				x++;
			}
			else{
				cnt+=a[x];
				x++;
				y--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
