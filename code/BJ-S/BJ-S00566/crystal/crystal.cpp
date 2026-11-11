#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long a[500005],qzh[500005],_min_xb=1,m,_min_ch=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		//cout<<a[i]<<' ';
		qzh[i]=qzh[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		if(i==1){
			_min_ch=qzh[n]-a[i]*n;
			_min_xb=i;
		}
		else if(i==n){
			long long q=(-qzh[n])+a[i]*n;
			if(q<=_min_ch){
				_min_ch=q;
				_min_xb=i;
			}
		}
		else{
			long long q=(a[i]*(i-1)-qzh[i-1]+(qzh[n]-qzh[i]-(n-i)*a[i]));
			if(q<=_min_ch){
				_min_ch=q;
				_min_xb=i;
			}
		}
	}
	//cout<<_min_ch<<' '<<_min_xb<<endl;
	for(int i=_min_xb;m>0 && i>=1;i--){
		m-=a[_min_xb]-a[i];
		ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
