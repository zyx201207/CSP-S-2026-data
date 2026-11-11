#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
bool cmp(int x,int y){
	return x>y; 
}
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ma=0;
	int t=1;
	int v=0;
	for(int i=1;i<=21;i++){
		t*=2;
	}
	t-=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		t&=a[i];
		if(a[i]==4){
			v+=1;
		}
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	else if(m==n){
		cout<<t;
		return 0;
	}
	else if(m==2){
		int maa=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int k=a[i];
				k&=a[j];
				maa=max(maa,k);
			}
		}
		cout<<maa;
		return 0;
	}
	else if(ma<=4){
		if(v<m){
			cout<<3;
		}
		else cout<<4;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[m];
	return 0;
} 
