#include <iostream>
using namespace std;
int n,cnt,nax,l,r,ll,rr,ans;
char d[2000005],f[2000005],ff[2000005],c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>cnt>>c;
		for (int j=1;j<=cnt;j++){
			nax++;
			d[nax]=c;
			cout<<d[nax]<<endl; 
		}
	}
	if (nax%2==0){
		l=1;r=nax/2;ll=nax/2+1;rr=nax;
	} 
	else{
		l=1;r=nax/2;ll=nax/2+2;rr=nax;
	}
	for (int i=l;i<=r;i++){
		f[i]=d[i];
		cout<<f[i]<<endl;
	}
	for (int i=ll;i<=rr;i++){
		ff[i]=d[i];
		cout<<f[i]<<endl;
	}
	for (int i=1;i<=nax/2;i++){
		if (ff[i]!=f[i]){
			ans++;
		} 
		cout<<ans;
	}
	return 0;
}
