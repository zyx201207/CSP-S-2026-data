#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1,last=1;i<=n;i++){
		m-=(i-last)*(a[i]-a[i-1]);
		if(m<0){
			while(m<0){
				m+=a[i]-a[last];
				last++;
			}
		}
		ans=max(ans,i-last+1);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
}
