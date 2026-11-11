#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,mk=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i){
			mk++;
		}
	}
	int fal=1;
	if(mk==n){
		for(int i=1;i<=n;i++){
			if(m-i>0){
				fal++;
				m-=i;
			}
		}
		cout<<fal;
		return 0;
	}
	int kk=a[2]-a[1],jm=0;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]==kk){
			jm++;
		}
	}
	if(jm==n-1){
		int jmm=1;
		for(int i=1;i<=n;i++){
			if(m-jm*i>0){
				jmm++;
				m-=jm*i;
			}
		}
		cout<<jmm;
		return 0;
	}
	
	sort(a+1,a+n+1);
	int maxn=-999;
	for(int i=n;i>=1;i--){
		int h4=1;
		int mm=m;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=mm){
				h4++;
				mm-=a[i]-a[j];
			}else{
				break;
			}
		}
		if(h4>maxn){
			maxn=h4;
		}
	}
	cout<<maxn;
	return 0;
}
