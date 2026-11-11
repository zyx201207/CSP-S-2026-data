#include<bits/stdc++.h>
using namespace std;

const int MAXN=500050;
long long n,m,a[MAXN],ans=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a,a+n);
	for(int i=2;i<=n;i++){
		if(a[1]==a[i])continue;
		if(a[1]<a[i] and (m-((i-1)*(a[i]-a[1])))>=0){
			m-=((i-1)*(a[i]-a[1]));
			for(int j=1;j<i;j++){
				a[j]=a[i];
			}
		}else break;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[1])ans++;
	}
	cout<<ans;
	return 0;
}
