//GZ-J00345 遵义市第四中学 李禹宸 
#include<bits/stdc++.h>
using namespace std;
int n;
struct str{
	char w;
	long long y;
}a[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].y>>a[i].w;
	}
	long long l=1,r=n;
	while(l<=r){
		if(a[l].w==a[r].w){
			if(a[l].y>=a[r].y){
				a[l].y-=a[r].y;
				r--;
			}else{
				a[r].y-=a[l].y;
				l++;
			}
		}else{
			if(a[l].y>=a[r].y){
				ans+=a[r].y;
				a[l].y-=a[r].y;
				r--;
			}else{
				ans+=a[l].y;
				a[r].y-=a[l].y;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
