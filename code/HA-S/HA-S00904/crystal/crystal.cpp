#include<bits/stdc++.h>
using namespace std;
long long m;
long long n,a[500010],shu[500010],b[2000],ks,kc,iii=1,qqqq=0,mm,ans=0,chao=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	memset(b,0,sizeof(b));
	cin>>n>>m;
	kc=sqrt(n);
	ks=(n-1)/kc+1; 
	for(int i=1;i<=n;i++){
		cin>>shu[i];
	}
	sort(shu+1,shu+n+1);
	for(int i=1;i<n;i++){
		a[i]=shu[i+1]-shu[i];
		if(i!=1&&a[i]!=a[i-1]){
			chao=0;
		}
	}
if(chao==1){
	m/=a[2];
	for(int i=1;chao==1;i++){
		if(m>=i){
		m-=i;	
		ans++;
		}
		else {
			cout<<ans<<"\n";
			return 0;
		}
	}
}
long long llq=0,ww=0,o;
	for(int i=1;i<n;i++){
		llq=0;
		ww=1;
		mm=m;
		o=i;
		while(mm>0&&o>=1){
			llq+=a[o];
			
			mm-=llq;
			ww++;
			o--;
			ans=max(ww,ans);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
