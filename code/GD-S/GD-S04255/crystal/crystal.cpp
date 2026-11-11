#include <bits/stdc++.h> 
using namespace std;
long long a[1000015],b[1000015];
int n;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	} 
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=i;j++){
//			if(a[j]>a[i]){
//				swap(a[j],a[i]);
//			}
//		}
//	}
	sort(a+1,a+n+1);	
	long long na,nb,sum,Max,cnt;
	Max=m;
	for(int i=n;i>=1;i--){
		cnt=0;
		int k;
		for(int j=1;j<i;j++){
			na=a[j],nb=a[i];
			sum=nb-na;
			if(sum<=Max){
				cnt++;
				Max-=sum;k=j;
			}else{
				break;
			}
		}
		k++;
		for(k;k<=n;k++){
			if(a[k]==a[i]){
				cnt++;
			}
		}b[i]=cnt;
	}
	long long tmax=-1;
	for(int i=1;i<=n;i++){
		if(b[i]>tmax){
			tmax=b[i];
		}
	}cout <<tmax;
	return 0;
}
