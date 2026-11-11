#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main(){
	freopen("string.in",r,stdin);
	freoprn("string.out",w,stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		cin >> c[i];
	}
	int l = 1,r = n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r-=1;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l+=1;
			}else{
				l+=1;
				r-=1;
			}
		}
		if(c[l]!=c[r]){
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r-=1;
			}else if(a[l]<a[r]){
				ans+=a[l];
				
				a[r]-=a[l];
				l+=1;
			}else{
				ans+=a[l];
				l+=1;
				r-=1;
			}
		}
	}
	cout << ans;
	return 0;
}
