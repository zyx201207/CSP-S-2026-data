#include <bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
long long n,m;
long long a[N],b[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>m;
	bool xb=true,xa=true,d=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&a[i]!=a[i-1]){
			xa=false;
		}else if(i!=1&&(a[i-1]+1)!=a[i]){
			xb=false;
		}else d=true;
	}
	
	if(xa){
		cout<<n;
	}else if(xb){
		long long sum=0;
		for(int i=1;i<=n;i++){
			if(m-i>=0){
				m-=i;
				sum++;
			}
		}
		cout<<sum+1;
	}

	return 0;
}
