#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+7;
int main(){
	int n;
	int m,an,a[maxn];
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]>a[j]){
				an=a[j];
				a[j]=a[i];
				a[i]=an;
			}
		}
	}
	long long num=0,ad=0,cnt,ans;
	while(ad<=m){
		num++;
		for(int i=num+1;i<=n;i++){
			cnt=num;
			ans=0;
			ad=1e9;
			if(cnt>0){
				ans+=a[i]-a[i-cnt];
				cnt--;
				}
			ad=min(ad,ans);
		}
		if(num>=1e8){
			cout<<n;
			return 0;
		}
	}
	cout<<num;
	return 0;
}
