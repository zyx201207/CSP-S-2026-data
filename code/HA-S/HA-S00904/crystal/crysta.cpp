#include<bits/stdc++.h>
using namespace std;
long long m;
long long n,a[500010],shu[500010],b[2000],ks,kc,iii=1,qqqq=0,mm,ans=0,chao=1;
//long long suan(int x){
//	long long qqa=0,ww=-1,yu=0,chh=0,llq=0;
//	if(x<kc){
//		for(int i=x-1;i>=1;i--){
//			llq+=a[i];
//			qqa+=llq;
//		if(mm>=llq){
//			ww++;
//			mm-=llq;
//		}
//		else {
//		
//		return ww;
//			break;
//		}
//		}
//		return ww;
//		
//	}
//	yu=x%kc;
//	if(yu!=0)
//	for(int i=x-1;i>=x-yu;i--){
//			llq+=a[i];
//			cout<<llq<<" llq ";
//			qqa+=llq;
//		if(mm>=llq){
//			ww++;
//			mm-=llq;
//		}
//		else {
//			return ww;
//			break;
//		}
//	}
//	cout<<llq;
//	x-=yu;
//	chh=x/kc;
//	for(int i=chh;i>=1;i--){
//			llq+=b[i];
//			qqa+=llq;
//		if(mm>=llq){
//			ww++;
//			mm-=llq;
//			x-=kc;
//		}
//		else {
//			return ww;
//			break;
//		}
//	}
//	while(mm>=llq&&x>=1){
//	 		llq+=a[x-1];
//			qqa+=llq;
//		if(mm>=llq){
//			ww++;
//			x--;
//		}
//		else {
//			return ww;
//			break;
//		}
//	}
//	return ww;
//}
int main(){
	freopen("crysta.in","r",stdin);
	freopen("crysta.out","w",stdout);
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
	
//	for(int i=1;i<=ks;i++){
//		for(int o=min(i*kc,n);o>(i-1)*kc;o--){
//			b[i]+=b[i]+a[o];
//		}
//	}
//	for(int i=1;i<=ks;i++){
//		cout<<b[i]<<" ";
//	}
//	for(int i=2;i<=n;i++){
//		mm=m;
//		ans=max(ans,suan(i));
//	}
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
