#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
long long a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		if(a[1]!=a[i])f=1;
	}
	if(f==0){
		cout<<a[1]<<'\n';
		return 0;
	}
	long long naxn=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]==a[j])continue;
			long long mm=a[i];
			for(int q=1;q<k;q++){
				mm=mm^a[j+q];
			}
		}
	}
	return 0;
}
