#include<bits/stdc++.h>
using namespace std;

long long n,m,i,j,t,f,s = 1,h,k,v;
long long a[500010];

bool A = true,B = true;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> a[1];
	if(n==1){
		cout << 1 << endl;
		return 0;
	}
	cin >> a[2];
	k = a[2]-a[1];
	for(i = 3;i<=n;i++){
		cin >> a[i];
		v = a[i]-a[i-1];
		if(a[i]!=i)A = false;
		if(v!=k)B = false;
	}
	if(A){
		for(i = 1;i<=n-1;i++){
			h += i;
			if(h>m){
				break;
			}
			s++;
		}
		cout << s << endl;
		return 0;
	}
	if(B){
		for(i = 1;i<=n-1;i++){
			h += k*i;
			if(h>m){
				break;
			}
			s++;
		}
		cout << s << endl;
		return 0;
	}
	sort(a+1,a+n+1);
//	for(i = 1;i<=n;i++){
//		h = 0;
//		for(j = i+1;j<=n;j++){
//			h += (a[j]-a[j-1])*(j-i);
//			if(h<=m){
//				s = max(j-i+1,s);
//			}
//			else{
//				break;
//			}
//		}
//	}
	for(i = 1;i<=n;i++){
		h = 0;
		for(j = i;j<=n;j++){
			h += a[n]-a[j];
		}
		if(h<=m){
			s = max(n-i+1,s);
			break;
		}
		for(j = n-1;j>=i+1;j--){
			h -= (a[j+1]-a[j])*(j-i+1);
			if(h<=m){
				s = max(j-i+1,s);
				break;
			}
		}
	}
	cout << s << endl;
	return 0;
}
