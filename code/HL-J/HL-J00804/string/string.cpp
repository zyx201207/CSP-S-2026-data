#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
char a[N];
ll n,x[N],ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> x[i] >> a[i];
	}
	for(int i=1,j=n;i<j;){
		if(a[i]!=a[j]){
			ans+=min(x[i],x[j]);
			if(x[i]>x[j]){
				x[i]-=x[j];
				j--;	
			}
			else if(x[i]<x[j]){
				x[j]-=x[i];
				i++;
			}
			else {
				i++,j--;
			}
		}
		else {
			if(x[i]>x[j]){
				x[i]-=x[j];
				j--;
			}
			else if(x[i]<x[j]){
				x[j]-=x[i];
				i++;
			}
			else {
				i++,j--;
			}
		}
	}
	cout << ans;
	return 0;
}