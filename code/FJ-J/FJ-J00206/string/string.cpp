#include<bits/stdc++.h>
using namespace std;
long long n,sum=0,ans=0;
char c;
struct Letter_{
	int num;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		sum+=a[i].num;
	}
	
	sum/=2;
	int zhi1=1,zhi2=n;
	for(int i=1;i<=sum;i++){
		if(a[zhi1].num<1){
			zhi1++;
		}
		if(a[zhi2].num<1){
			zhi2--;
		}
		if(a[zhi1].c != a[zhi2].c){
			ans++;
		}
		a[zhi1].num--;
		a[zhi2].num--;
	}
	cout<<ans;
	return 0;
}
