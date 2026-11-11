//GZ-J00628，邱光伍，贵阳市第三实验中学
#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=2*1e5+5;
ull n,sum;
ull a[N];char b[N];
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(int i=1,j=n;i<j;i++,j--){
		if(b[i]!=b[j]){
			sum+=max(a[i],a[j]);
		}
	}
	cout<<sum; 
	return 0;
} 
