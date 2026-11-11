#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a;
	long long b;
	cin>>a>>b;
	long long c[10000000];
	for (int i=1;i<=a;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+a);

	int ans=1;
	int zan;
	int zanzan=1;
	for (int i=a;i>=1;i--){
		zan=0;
		for (int j=i-1;j>=1;j--){
			zan+=c[i]-c[j];
			zanzan++;
			if (zan>b){
				zanzan=zanzan-1;
				ans=max(zanzan,ans);
				zanzan=1;
				break;
			}if (zan==b){
				ans=max(ans,zanzan);
				break;
			}
		}
	}
	cout<<ans;
}
