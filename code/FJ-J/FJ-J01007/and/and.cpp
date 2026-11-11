#include<iostream>
#include<cstdio>
int n,m;
int a[200005],t[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	std::cin>>n>>m;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	for(int l=30;l>=0;l--){
		int tn=0;
		for(int i=1;i<=n;i++){
			if((1<<l)&(a[i])){
				tn++;
				t[tn]=a[i];
			}
		}
		if(tn>=m){
			n=tn;
			for(int i=1;i<=n;i++){
				a[i]=t[i];
			}
		}
	}
	int ans=0x7fffffff;
	for(int i=1;i<=n;i++){
		ans&=a[i];
	}
	std::cout<<ans;
	return 0;
}
/*
std::cout<<"200000 1\n";
	for(int i=1;i<=200000;i++){
		std::cout<<"65535\n";
	}
	*/
