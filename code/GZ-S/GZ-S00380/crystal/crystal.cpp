//GZ-S00380 贵阳市新世界学校 孙熙锐 
#include<bits/stdc++.h> 
using namespace std;
const int N=50010;
long long n,m,a[N],maxn=INT_MAX,k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=n;i>1;i--){
		long long cha=0;
		for(int j=1;j<i;j++)cha+=a[i]-a[j];
		if(abs(maxn-m)>abs(cha-m)){
			 maxn=min(maxn+i,cha);
			 k=i;
		}
	}
		cout<<maxn;
	
	
	
	return 0;
}
