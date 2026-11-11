#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long 
#define endl '\n' 
const int M=2e5+67;
ll l=0,ans=0;
int n,a[M];
char c[M];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		int x;
		char m;
		cin >> x >> m;
		a[i]=x; 
		c[i]=m;
		l+=1LL*x;
	} 
	int l=1,r=n;
	while(l!=r){
		if(a[l]>=a[r]){
			if(c[l]==c[r]){
				a[l]-=a[r];
				a[r]=0;
			}else{
				ans+=1LL*a[r];
				c[r]=c[l];
				a[l]-=a[r];
				a[r]=0;
			}
			r--;
		}else{
			if(c[l]==c[r]){
				a[r]-=a[l];
				a[l]=0;
			}else{
				ans+=1LL*a[l];
				a[r]-=a[l];
				a[l]=0;
			}
			l++;
		}
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


