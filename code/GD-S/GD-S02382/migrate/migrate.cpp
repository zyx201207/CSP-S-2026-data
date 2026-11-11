#include <bits/stdc++.h>
using namespace std;
long long a[2000005];
int dd[2000005];
long long l;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	c++;
	for (int k=1;k<=T;k++){
		int n;
	cin>>n>>l;
	if (n<4){
		cout <<0;
		continue;
	}
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int cnt=0;
	for (int i=n;i>=3;i--){
		if (a[i]-a[i-1]<=l&&a[i]-a[i-2]>=l){
			dd[i-1]=dd[i]+1;
		}
	}
	for (int i=1;i<=n;i++){
		if (a[i+1]-a[i]<=l&&a[i+2]-a[i+1]<=l&&a[i+3]-a[i+2]<=l&&a[i+2]-a[i]>=l&&a[i+3]-a[i+1]>=l){
			cnt+=dd[i+3]+1;
		}
	}
	cout <<cnt<<endl;
}
	return 0;
} 
