#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int n,m,a[N],ans=0,b,q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int b=0;
		if(a[i]==a[i+1]){
			ans++;
		}
		if(a[i]<a[i+1]){
			b=a[i+1]-a[i];
		}else{
			b=a[i]-a[i+1];
		}
		if(b>q){
			q=b;
		}else{
			continue;
		}
		for(int j=2;j<=m;j++){
			m-=q;
			ans++;
			if(m<=0){
				break;
			}
		}
}
	cout<<ans<<endl;
	return 0;
} 
