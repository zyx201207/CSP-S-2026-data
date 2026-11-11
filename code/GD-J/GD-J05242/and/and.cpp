#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a,b,c[100000005],maxn=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a;i++) cin>>c[i];
	for(int i=0;i<a;i++){
		for(int j=i+1;j<a;j++){
			int m;
			m=c[i]&&c[j];
			if(m>maxn) maxn=m;
		}
	}
	cout<<c[a-1]&&c[a-2];
	return 0;
}
