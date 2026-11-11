//GZ-J00085 贵阳市第二实验中学 杨浩然
#include <bits/stdc++.h>
const int N=2e5+5;
char c[N];
long long a[N];
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(r-l>0){
		long long x=min(a[l],a[r]);
		if(c[l]!=c[r]){
			sum+=x;
		}
		a[l]-=x;
		a[r]-=x;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<sum;
	return 0;
}

