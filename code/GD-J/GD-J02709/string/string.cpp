#include<iostream>
#include<cstring>
#define N 200005
using namespace std;
int n,a[N];
char c[N];
unsigned long long cd=0,ans=0;
int tp=0;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(i!=1&&c[i]!=c[i-1]) tp=1;
		cd+=a[i];
	}
	if(tp==0){
		cout<<0;
		return 0;
	}
	int l=1,r=n;
	unsigned long long cl=0;
	char x,y;
	while(cl<cd/2&&l<r){
		x=c[l],y=c[r];
		if(x!=y){
			cl+=min(a[l],a[r]);
			ans+=min(a[l],a[r]);
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else if(a[l]==a[r]) l++,r--;
			else{
				a[l]-=a[r];
				r--;
			}
		}
		else{
			cl+=min(a[l],a[r]);
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else if(a[l]==a[r]) l++,r--;
			else{
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
