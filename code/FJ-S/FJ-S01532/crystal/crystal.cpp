#include<bits/stdc++.h>
using namespace std;
long long n,m,cishu=1,sum,b=0;
long long a[500010],chazhi[500010],c[500010];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	//º∆À„≤Ó÷µ 
	for(int i=2;i<=n;i++){
		chazhi[i]=a[i]-a[i-1];
	}
	
	b=n;
 	for(int i=n;i>=1;i--){
		cishu++;
		for(int j=b;j>=i;j--){
			sum+=chazhi[j];
		}
		if(sum>m){
			cishu--;
			sum-=chazhi[b]*cishu;
			b--;	
		}
	}
	cout<<cishu;

//	for(int k=n;k>=2;k--){
//		cishu=1;
//		sum=0;
//		for(int i=k;i>=2;i--){
//			cishu++;
//			sum+=chazhi[i]+sum;
//			if(sum>m){
//				c[k]=cishu--;
//				continue;	
//			}
//			
//		
//		}
//	}
//	for(int i=1;i<=n;i++){
//		if(c[i]>b){
//			b=c[i];
//		}
//	}
//	cout<<b;
	
	
	
	
	return 0;
}
