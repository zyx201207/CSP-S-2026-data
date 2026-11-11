#include <bits/stdc++.h>
using namespace std;
long long a[200005];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[n];
	}sort(a+1,a+n+1,cmp);
	int s=a[1];
	for(int i=2;i<=n;i++){
		s=s&a[i];
	}
	int m;
	cin>>m;
	if(m==n){cout<<s;return 0;
	}
	if(m==1){cout<<a[n];
	return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int num;
			num=a[i]&a[j];
			ans=max(ans,num);
		}
	}cout<<ans;
	return 0;
}
