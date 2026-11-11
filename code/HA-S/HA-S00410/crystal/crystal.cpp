#include <bits/stdc++.h>
using namespace std;
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
	long long n,m,a[100001],arr=0;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sort(a+1,a+n+1);
	}
	for(int i=2;i<=n;i++){
		int q1=0,q2=0;

		for(int j=1;j<i;j++){
		if (a[i]=a[j]){
			q1 += a[i]-a[j];
			if((q1>=0)&&(m-q1)>=0){
			q2++;	
			}
			else {
			break;	
			}
		}else if(a[i]==a[j]){
		q2++;
		}
		}
		q2++;
    arr=max(arr,q2);     
 }
 cout<<arr;
 	return 0;
}







