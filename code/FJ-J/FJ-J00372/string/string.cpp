#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int a[MAXN],p[MAXN];
char c[MAXN];
string ans="0";
void pl(int x){
	int e,n,t=1;
	while(x>0){
		e=x%10;
		if(ans.size()<t){
			ans='0'+ans;
		}
		n=ans.size()-t;
		ans[n]+=e;
		if(ans[n]>'9'){
			//½øÎ» 
			while(n>0&&(ans[n-1]>='9'||ans[n]>='9')){
				ans[n-1]++;
				ans[n]-=10;
				n--;
			}
			if(n==0&&ans[n]>='9'){
				ans[n]-=10;
				ans='1'+ans;
			}
		}
		t++;
		x/=10;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ind=1;
	cin >> n;
	
	for(int i=1;i<=n;i++)cin >> a[i] >> c[i];
	int l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			if(a[l]<a[r]){
				p[ind]=a[l];
				a[r]-=a[l];
				ind++;
				l+=1;
				continue;
			}
			if(a[l]>a[r]){
				p[ind]=a[r];
				a[l]-=a[r];
				ind++;
				r-=1;
				continue;
			}
			if(a[l]==a[r]){
				p[ind]=a[l];
				ind++;
				l+=1;
				r-=1;
				continue;
			}
		}
		else{
			if(a[l]<a[r]){
				a[r]-=a[l];
				l+=1;
				continue;
			}
			if(a[l]>a[r]){
				a[l]-=a[r];
				r-=1;
				continue;
			}
			if(a[l]==a[r]){
				l+=1;
				r-=1;
				continue;
			}
		} 
	}
	for(int i=1;i<ind;i++){
		pl(p[i]);
	}
	cout << ans;
	return 0;
}
