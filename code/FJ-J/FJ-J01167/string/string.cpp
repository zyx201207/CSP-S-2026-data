#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+3;

int n;
ll a[N];
char c[N];

ll ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,j=n;
	while(i<j){
		while(a[i]){
			if(a[i]>=a[j]){
				a[i]-=a[j];
				if(c[i]!=c[j]){
					ans+=a[j];
					//cout<<a[j]<<'\n';
				}
			}
			else break;
			j--;
		}
		if(a[i]){
			if(c[i]!=c[j]){
				ans+=a[i];
				//cout<<a[i]<<'\n';
			}
			a[j]-=a[i];
		}
		if(a[j]==0)j--;
		i++;
	}
	cout<<ans;
	return 0;
} 





