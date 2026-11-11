#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,a[N];
long long ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<=j;){
		if(c[i]!=c[j]){
			if(a[i]<a[j]){
				a[j]-=a[i];
				ans+=a[i];
				i++;
			}else{
				a[i]-=a[j];
				ans+=a[j];
				if(a[i]==0)i++;
				j--;
			}
		}else{
			if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else{
				a[i]-=a[j];
				if(a[i]==0)i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
