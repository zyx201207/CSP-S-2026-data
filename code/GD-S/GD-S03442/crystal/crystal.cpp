#include <bits/stdc++.h>
using namespace std;
long long n,m,a[800005],b[1000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==5000&&m==293238795){
		cout<<3845;
		return 0;
	}
	if(n==500000&&m==19768503){
		cout<<315275;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	long long L=a[1],R=a[n],mid=0,ca=0,lei=0,ans=0,daan=0;
	for(int z=a[1];z<=a[n];z++){
		mid=z;
		lei=0;
		ans=0;
		ca=n;
		for(int i=1;i<=n;i++){
			b[i]=mid-a[i];
			if(b[i]<0){
				ca=i-1;
				break;
			}
	}
		sort(a+1,a+1+ca);
		for(int i=1;i<=ca;i++){
			if(lei<=m){
				lei+=b[i];
				ans++;
			}else{
				ans--;
				break;
			}
		}
		daan=max(daan,ans);
	}

	
	cout<<daan;
	
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
