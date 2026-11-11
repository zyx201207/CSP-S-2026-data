//GZ-S00153 遵义市播州区新蓝学校 王天垚 
#include<bits/stdc++.h>
using namespace std;
int n;long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	int a[n+1],b[n+1];
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		long long c=m;
		for(int j=i-1;j>=1;j--){
			int t=a[i]-a[j];
			if((c-t)>=0){
				c-=t;
				b[i]++;
			}else break;
		}
	}
	int mx=1;
	for(int i=2;i<=n;i++){
		if(b[mx]<b[i])
		mx=i;
	}
	cout<<b[mx]+1;
	return 0;
}
