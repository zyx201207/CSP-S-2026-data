#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7; 
#define ll long long
ll n,ans=0,a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<j;){
		if(c[i]==c[j]){
			if(abs(i-j)==1){
				i++;j--;
				continue;
			}
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
				continue;
			}
			else if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
				continue;
			}
			else if(a[i]==a[j]){
				i++;j--;
				continue;
			}
		}
		else if(c[i]!=c[j]){
			ans+=min(a[i],a[j]);
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
				continue;
			}
			else if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
				continue;
			}
			else if(a[i]==a[j]){
				i++;j--;
				continue;
			}
		}
	}cout<<ans;
	return 0;
}
