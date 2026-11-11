//
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<char>c;
vector<ll>d;
ll dls,n,ans=0;
char cls;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin>>n;
	for(int i=0; i<n; i++){
		cin>>dls>>cls;
		d.push_back(dls);
		c.push_back(cls);
	}
	ll L=0,R=c.size()-1;
//	cout<<L<<R;
	while(L<R){
//		for(int i=L; i<=R; i++){
//			cout<<d[i]<<' '<<c[i]<<'\n';
//		}cout<<"______\n";
		if(d[L]>d[R]){
			if(c[L]!=c[R])ans+=d[R];
				d[L]-=d[R];
				d[R]=0;
		}else{
			if(c[L]!=c[R])ans+=d[L];
				d[R]-=d[L];
				d[L]=0;
		}
		if(d[R]<=0){
			R--;
		}if(d[L]<=0){
			L++;
		}
		
	}
//	for(int i=L; i<=R; i++){
//			cout<<d[i]<<' '<<c[i]<<'\n';
//		}cout<<"______\n";
	cout<<ans;
	return 0;
}//479681762610
