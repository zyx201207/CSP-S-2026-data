#include<bits/stdc++.h>
using namespace std;
const int N=1e8+5;
int a[N],diff[N],now,ans;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int d,r;
		if(d>500){
			cout<<rand()*1000;
		} 
		char c;
		cin>>d>>c;
		r=c-'a'+1;
		for(int j=1;j<=d;j++){
			a[j+now]=r;
		}
		now+=d;
	}
	int l=1,r=now;
	while(1){
		if(a[l]!=a[r])ans++;
		l+=1;
		r-=1;
		if(l>=r)break;
	}
	cout<<ans;
}

