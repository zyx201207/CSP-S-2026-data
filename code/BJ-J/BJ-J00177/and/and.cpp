#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans,mans;
long long a[200005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	bool b=1;
	long long ma=0;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
		cin >> a[i];
		ma=max(ma,a[i]);
	}
	if(m==1){
	    cout << ma;
	    return 0;	
	}
	if(m==n){
		long long an=a[1];
		for(int i=2;i<=n;i++){
			an=an&a[i];
		}
		cout << an;
		return 0;
	}
	//if(m==n-1){
	//	for(int i=1;i<=n;i++){
	//		
	//	}
	//}
	for(int i=1;i<=n;i++){
		if(pow(2,log2(a[i]+1))!=a[i]+1)b=0;
	}
	if(b){
		sort(a+1,a+n+1,cmp);
		cout << a[m];
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans=a[i];
	    for(int j=1;j<m;j++){
			ans&=a[i+j];
			//cout << ans << ' ' << i << ' ' << j << endl;
		}	
		mans=max(mans,ans);
	}
	//for(int i=1;i<=n;i++){
	//	
	//}
	cout << mans;
	return 0;
}