#include<bits/stdc++.h>
using namespace std;
int n;
long long m,k=-1,a[500010];
//bool fa=1,fb=1,fc=1;
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		/*if(a[i]!=i) fa=0;
		if(i>2) if(a[i]-a[i-1]!=a[i-1]-a[i-2]) fb=0;
		if(a[i]!=a[i-1]) fc=0;*/
	}
	sort(a+1,a+1+n);
	/*if(fa||fb||fc){
		int b=a[2]-a[1];
		int u=m/b,s=0,k;
		k=u+sqrt(u*2)/2;
		u-=k;
		s=sqrt(u*2);
		for(int i=sqrt(u*2);i<u;i++){
			s++;
			u-=i;
		}
		cout<<s;
		return 0;
	}*/
	for(int i=n;i>=k;i--){
		if(a[i+1]==a[i]&&i!=n) continue;
		long long s=0,l=0;
		for(int j=i;j>=1&&m-s>=a[i]-a[j];j--,l++){
			s+=a[i]-a[j];
			/*if(a[j]==a[j-32]){
				j-=16;
				l+=16;
			}
			if(a[j]==a[j-16]){
				j-=8;
				l+=8;
			}
			if(a[j]==a[j-8]){
				j-=4;
				l+=4;
			}*/
			//cout<<s<<" "<<j<<"\n";
		}
		k=max(l,k);
		//cout<<l<<" ";
		//if(k==315275) break;
	}
	cout<<k;
	return 0;
} 
