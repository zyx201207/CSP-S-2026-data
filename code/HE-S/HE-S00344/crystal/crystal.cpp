#include<bits/stdc++.h>
using namespace std;
int a[1000000000005],co[1000000000005],shi[1000000000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans_caonimabi,cnt=1;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n+1);
	for(int j=0;j<n;j++){
		co[j]=a[j+1]-a[j];
		shi[j]=a[j+1]-a[j];
	}
	sort(co,co+n+1);
	for(int k=n;k>=0;k--){
		if(co[0]==shi[k]){
			ans_caonimabi=k;
			break;
		}
	}
	for(int wc=ans_caonimabi;wc>=0;wc--){
		m=m-(shi[wc]-shi[wc-1]);
		if(m<=0){
			break;	
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}
