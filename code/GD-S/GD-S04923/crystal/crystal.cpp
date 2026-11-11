#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m;
int a[500005];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m >> a[1] >> a[2];
	int x=a[2]-a[1];
	a[1]/=x;
	a[2]/=x;
	int y=a[1]-1;
	a[1]-=y;
	a[2]-=y;
	for(int i=3;i<=n;i++){
		cin >> a[i];
		a[i]/=x;
		a[i]-=y;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]+a[i]-1;
		ans++;
		if(a[i]>m){
			cout << ans-1;
			break;
		}else if(a[i]==m){
			cout <<ans;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
} 
