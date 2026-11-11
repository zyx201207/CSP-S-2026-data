#include<bits/stdc++.h>
using namespace std;
int jkkj,t,n,m,a[2000005],mid,yu;
int f(int l,int r,int dep,int ans){
	if(dep==mid&&ans==yu)return 1;
	int mid=(r-l+m)/m,yu=a[r]-a[l],s=0;
	for(int i=l;i<=r;i++){
		s+=f(l,r,dep+1,ans+a[i]);
	}
	return s==2;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>jkkj>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long len=a[2]-a[1],g=1,sum=0;
		for(int i=n;i>=2;i--){
			if(a[i]-a[i-1]!=len)g=0;
		}
		if(g){
//			if(m%2==1){
//				cout<<"0\n";
//			}else{
				for(int i=1;i<=n;i++){
				mid=(1+2*m)/m;yu=a[i+m+1]-a[i];
					if(f(i,i+m+1,0,0))sum++;
				}
				cout<<sum<<"\n";	
//			}
			
		}else{
			int sum=0,akak=1,maxn=-111111111,maxnn=-111111111,nl[100005],nr[100005],ni=1;
			while(akak<n){
				int lenlen=a[akak+1]-a[akak],sumsum=1,yan=akak;
				akak++;
				while(a[akak+1]-a[akak]==lenlen){
					sumsum++;
					akak++;
				}
				if(sumsum>=maxnn){
					nl[ni]=yan;
					nr[ni]=akak;
					maxnn=sumsum;
					ni++;
				}
			}
			for(int j=1;j<=ni;j++){
				for(int i=nl[j];i<=nr[j];i++){
					mid=(nr[j]-nl[j])/m;yu=a[nr[j]]-a[nl[j]];
					if(f(nl[j],nr[j],0,0))sum++;
				}
				maxn=max(maxn,sum);
			}
			cout<<maxn<<"\n";
		}
	} 
	return 0;
}

