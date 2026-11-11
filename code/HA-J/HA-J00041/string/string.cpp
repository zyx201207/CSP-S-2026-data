#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int a[N],n;
char b[N];
ll ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int i=1,j=n;
	while(i < j){
		if(b[i] == b[j]){
			if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}
			else if(a[j]<a[i]){
				a[i]-=a[j];
				j--;
			}
			else{
				i++;j--;
			}
		}
		else{
			if(a[i]<a[j]){
				a[j]-=a[i];
				ans+=a[i];
				i++;
			}
			else if(a[j]<a[i]){
				a[i]-=a[j];
				ans+=a[j];
				j--;
			}
			else{
				ans+=a[i];
				i++;j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
