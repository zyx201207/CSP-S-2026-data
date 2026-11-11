#include<bits/stdc++.h>
using namespace std;
int n,m,cnt1,cnt2,cnt3;
int a[200010];
bool f=true;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnt1++;
		}else if(a[i]==2){
			cnt2++;
		}else if(a[i]==3){
			cnt3++;
		}
		if(a[i]>=4){
			f=false;
		}
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
	}else if(f){
		if(cnt3>=m){
			cout<<3;
		}else if(cnt3+cnt2>=m){
			cout<<2;
		}else if(cnt3+cnt1>=m){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}
