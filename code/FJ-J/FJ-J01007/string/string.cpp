#include<iostream>
#include<cstdio>
int n;
long long a[200005],al[200005],ar[200005],m,ml,mr;
char c[200005],cl[200005],cr[200005];
long long f(){
	long long ir=0,ll=0,lr=0,i=1,j=0,ans=0;
	while(i<=ml){
		while(ll>=lr){
			ir++;
			lr+=ar[ir];
		}
		if(al[i]-j+ll<lr){
			char ca=cl[i],cb=cr[ir];
			if(ca!=cb){
				ans+=al[i]-j;
			}
			ll+=al[i]-j;
			i++;
			j=0;
		}
		else{
			char ca=cl[i],cb=cr[ir];
			if(ca!=cb){
				ans+=lr-ll;
			}
			j+=lr-ll;
			ll+=lr-ll;
		}
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::cin>>n;
	if(n==1){
		std::cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		std::cin>>a[i]>>c[i];
		m+=a[i];
	}
	if(n==2){
		if(c[1]==c[2]){
			std::cout<<0;
			return 0;
		}
		if(a[1]<a[2]){
			std::cout<<a[1];
		}
		else{
			std::cout<<a[2];
		}
	}
//	long long lc,rc;
//	if(m%2==0){
//		lc=m/2-1;
//		rc=m/2;
//	}
//	else{
//		lc=m/2-1;
//		rc=m/2+1;
//	}
	long long li=1,ri=n,ll=0,lr=0;
	while(ll<m/2){
		if(ll+a[li]>m/2){
			ml++;
			al[ml]=(m/2-ll);
			cl[ml]=c[li];	
			ll+=(m/2-ll);
			break;
		}
		ml++;
		al[ml]=a[li];
		cl[ml]=c[li];
		ll+=a[li];
		li++;
	}
	while(lr<m/2){
		if(lr+a[ri]>m/2){
			mr++;
			ar[mr]=(m/2-lr);
			cr[mr]=c[ri];	
			lr+=(m/2-lr);
			break;
		}
		mr++;
		ar[mr]=a[ri];
		cr[mr]=c[ri];
		lr+=a[ri];
		ri--;
	}
//	for(int i=1;i<=ml;i++){
//		std::cout<<al[i]<<' '<<cl[i]<<'\n';
//	}
//	std::cout<<"----------\n";
//	for(int i=1;i<=mr;i++){
//		std::cout<<ar[i]<<' '<<cr[i]<<'\n';
//	}
	std::cout<<f();
	return 0;
}
