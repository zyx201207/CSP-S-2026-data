#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],d,ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i] >> c[i];
	}
	for(int i=0,j=n-1;i<j;i++){
		while(a[i]&&i<j){
			d=min(a[i],a[j]);
			a[i]-=d,a[j]-=d;
			if(c[i]!=c[j]){
				ans+=d;
			}
			if(a[j]==0){
				j--;
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
}
