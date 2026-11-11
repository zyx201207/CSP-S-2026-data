#include<bits/stdc++.h>
using namespace std;
int n,a[500005],maxx=1,sum;
bool f=0;
long long m;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int j=1;j<=a[n];j++){
		for(int k=1;k<=n;k++){
			if(a[k]==j){
				f=1;
				break;
			}
		}
		if(f==0) continue;
		f=0;
		for(int i=j;i>=1;i--){
			if(j-a[i]>0&&i-(j-a[i])>0){
				sum++;
				i-=j-a[i];
			}
		}
		maxx=max(sum,maxx);
		sum=0;
	}
	cout<<maxx;
	return 0;
} 
