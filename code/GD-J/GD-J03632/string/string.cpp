#include<bits/stdc++.h>
using namespace std;
const int N=200007;
long long a[N],n,y,ae[N],x,bi;
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		y+=a[i];
		ae[i]=-ae[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		if(y/2<ae[i]){
			x=i;
			break;
		}
	}
	int s=0;
	for(int i=1;i<=x;i++){
		for(int j=n;j>=x;j--){
			if(b[i]==b[j]){
				s+=a[j];
			}
		}
	}
	cout<<x-s;
	return 0;
} 
