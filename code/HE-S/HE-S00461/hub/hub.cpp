#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k,ans=0;
	int q1,q2,a[10001];
	cin>>c>>t;
	cin>>n>>k;
	for(int i=0;i<=n-1;i++){
		cin>>q1>>q2;
		a[i]=q1;
		a[i+1]=q2;
		if(q1==q2){
			ans=ans+1;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);//ACCSP
}
