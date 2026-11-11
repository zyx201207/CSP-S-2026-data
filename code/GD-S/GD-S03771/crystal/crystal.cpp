#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll n,m,a[N],shengyu;
bool flag=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	shengyu=m;
	sort(a+1,a+1+n);
	while(flag){
		flag=0;
		for(int i=1;i<=n-1;i++){
			if(a[i+1]-a[i]<=shengyu && a[i+1]!=a[i]){
				shengyu-=a[i+1]-a[i];
				a[i]=a[i+1];
				flag=1;
			}else break;
		}
	}
	int ma=INT_MIN,tmp=1;
	for(int j=2;j<=n;j++){
		if(a[j]!=a[j-1]){
			ma=max(ma,tmp);
			tmp=1;
		}else if(a[j]==a[j-1]){
			tmp++;
		}
	}
	cout<<ma<<endl;
	return 0;
}


