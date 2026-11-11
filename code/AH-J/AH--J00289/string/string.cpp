#include<bits/stdc++.h>
using namespace std;
struct ee{
	int x;
	char y;
}a[200005];
int n;
unsigned long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i].x,&a[i].y);
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].x>a[r].x){
			if(a[l].y!=a[r].y) ans+=a[r].x;
			a[l].x-=a[r].x;
			a[r].x=0;
			r--;
		}
		else if(a[l].x<a[r].x){
			if(a[l].y!=a[r].y) ans+=a[l].x;
			a[r].x-=a[l].x;
			a[l].x=0;
			l++;
		}
		else{
			if(a[l].y!=a[r].y){
				ans+=a[l].x;
				a[l].x=0;
				a[r].x=0;
				l++,r--;
			}
			else{
				l++,r--;
			}
		}
	}
	cout<<ans;
}
