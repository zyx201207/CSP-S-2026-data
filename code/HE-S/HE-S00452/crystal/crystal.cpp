#include <bits/stdc++.h>
using namespace std;

bool man(long long a,long long b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
    long int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n,man);
	if(n==1){
		cout<<1;
		return 0;
	}long long da=0;
	int ent=0;
	///cout<<m;
	
	for(int i=n-1;i>0;i--){
		if(a[i]==da&&ent!=0)
			continue;
		if(i<ent)
			break;
		long long jia=m;
		long long leiji=1;
		for(int l=i-1;l>=0;l--){
			if(jia>=a[i]-a[l]){
				jia-=a[i]-a[l];
			//	cout<<a[l]<<" ";
				leiji++;
			}else{
				break;
			}
		}if(leiji>ent){
			ent=leiji;
			da=a[i];
		}
	}printf("%d",ent);
	return 0;
} 
