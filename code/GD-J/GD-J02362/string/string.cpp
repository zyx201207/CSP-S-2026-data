#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	long long n,cnt=0,ans=0;
	bool flag;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(c[l]!=c[r]){
			ans+=cnt;
			if(flag)a[r]-=cnt;
			else a[l]-=cnt;
			ans+=min(a[l],a[r]);
			if(c[l]<c[r]){
				cnt=a[r]-a[l];
				flag=0;
			}
			else flag=1;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
