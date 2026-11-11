#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define filename "crystal" 

int n,m,a[500005],b[500005],c[500005],ans;

void AB(){
	int f = a[1];
	for(int i = 1;i<=n;i++){//暴力 
		int num = a[i]-f;//这个数和上个数的差 
		if(m-num*ans>=0){
			m-=num*ans;
			ans++;
			f = a[i];
		}
		else break;
	}
	cout << ans;
}

signed main(){
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	
	cin >> n>>m;
	
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}	
	sort(a+1,a+1+n);
	
	int l = 1,r,fnum = 0,f = 0;
	int fans = 1;
	
	for(int i = 2;i<=n;i++){
		b[i] = a[i]-a[i-1];
		c[i] = b[i]+c[i-1];
		if(f == 0){
			if(fnum+b[i]*fans<=m){
				fnum +=b[i]*fans;
				fans++;
			}
			else {
				f = 1;
				r = i-1;
			}
//			cout << fnum<<' '<<fans<<endl;
		}
	}
//	cout <<endl<< fans<<endl;
//	for(int i = 1;i<=n;i++){
//		cout << b[i]<<' ';
//	}cout << endl;
//	for(int i = 1;i<=n;i++){
//		cout << c[i]<<' ';
//	}cout << endl;
	ans = fans;
	
	while(r<n&&l<r){
		if(fnum+(fans+1)*b[r+1]>m){
			fnum=fnum-c[r]+c[l];
			l++;
			fans--;
			
//			cout << l<<' '<<r<<' '<<fans<<endl;
		}
		else{
			r++;
			fans++;
			fnum+=fans*b[r];
			ans = max(fans,ans);
//			cout << l<<' '<<r<<' '<<fans<<endl;
		}
	}
	cout << ans;
	
//	AB();
	return 0;
}//95tps
