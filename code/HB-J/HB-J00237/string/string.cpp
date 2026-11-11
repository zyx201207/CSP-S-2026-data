#include <bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n,sum1=a[1],sum2=a[n],ans;
	while(l<r){
		if(c[l]==c[r]){
			if(sum1>sum2){
				sum1-=sum2;
				r--;
				sum2=a[r];
			}
			else if(sum2>sum1){
				sum2-=sum1;
				l++;
				sum1=a[l];
			}
			else{
				l++;
				r--;
				sum1=a[l];
				sum2=a[r];
			}
		}
		else{
			if(sum1>sum2){
				sum1-=sum2;
				ans+=sum2;
				r--;
				sum2=a[r];
			}
			else if(sum2>sum1){
				ans+=sum1;
				sum2-=sum1;
				l++;
				sum1=a[l];
			}
			else{
				ans+=sum1;
				l++;
				r--;
				sum1=a[l];
				sum2=a[r];
			}
		}
		
	}
	cout<<ans;
	return 0;
}
/*
 * 6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
* */
 
