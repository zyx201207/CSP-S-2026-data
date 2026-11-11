#include<bits/stdc++.h>
using namespace std;
struct coco{
	long long sum;
	char x;
}a[200024];
long long n,ans,s;
char m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].sum>>a[i].x;
	}int l=1,r=n;
	while(l<=r){
		if(a[l].x==a[r].x){
			if(a[l].sum>a[r].sum){
				a[l].sum-=a[r].sum;
				r--;
			}else if(a[l].sum<a[r].sum){
				a[r].sum-=a[l].sum;
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(a[l].sum>a[r].sum){
				ans+=a[r].sum;
				a[l].sum-=a[r].sum;
				r--;
			}else if(a[l].sum<a[r].sum){
				ans+=a[l].sum;
				a[r].sum-=a[l].sum;
				l++;
			}else{
				ans+=a[l].sum;
				l++;
				r--;
			}
		}
	}cout<<ans<<endl;
	return 0;
}

