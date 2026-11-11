#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans,res;
bool ld;
int n,a[200005],l,r;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cin>>c[i];
	}
	l=1,r=n;
	while(l<r){
		if(a[l]>a[r]){
			ld=1;
			res=a[l]-a[r];
		}else{
			ld=0;
			res=a[r]-a[l];
		}
		if(c[l]!=c[r]){
			ans+=min(a[l],a[r]);
		}
		if(res!=0){
			if(ld){
				a[l]=res;
				r--;
			}else{
				a[r]=res;
				l++;
			}
		}else{
			l++;
			r--;
		}
	}	
	cout<<ans;
	return 0;
}

