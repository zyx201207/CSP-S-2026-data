#include <bits/stdc++.h>
using namespace std;
int n;
long long m,m1,a[500010],mx,num=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=0;i<n;i++){
		m1=m;
		num=1;
		while(m1>=0&&num+i<=n){
			m1-=num*(a[num+i]-a[num+i-1]);
			if(m1<0){
				break;
			}else{
				num++;
			}
		}
		mx=max(mx,num);
	}
	cout<<mx;
	return 0;
}
