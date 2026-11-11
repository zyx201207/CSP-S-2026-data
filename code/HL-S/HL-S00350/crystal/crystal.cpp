#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const long long L=-1e15;
long long n,m,minn=L,sum;
long long a[N],b[N],f,pre[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
    	cin >> a[i];
	}
	sort(a+1,a+1+n);
	 for(int i=1;i<=n;i++){
    	pre[i]=pre[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		b[i]=a[i]*(i-1)-pre[i-1];
	}
	//cout << minn;
	for(int i=1;i<=n;i++){
		if(b[i]>=minn && b[i]<=m){
			minn=b[i];
			sum=i;
		}
	}
	cout << sum;
    return 0;
}
//5 5
//1 2 4 8 9
