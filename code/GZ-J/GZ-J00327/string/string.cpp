//GZ-J00327 遵义市第十九中学 张锣址杨
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long  a[n+5],maxx=0;
	char b[n+5];
	for(long long i =0;i < n;i++){
		cin >> a[i]>>b[i];
	}
	long long k=0;
	if(n%2==0){
		k=1;
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	for(long long  i = 0,j=n-1;i<n/2,j>n/2-k;i++,j--){
		if(i!=0){
			a[i]+=a[i-1];
			a[j]+=a[j+1];
		}

		if(b[i]==b[j]){
			if(a[i]>a[j]){
				a[i]=a[i]-a[j];
				a[j]=0;
			}else{
				a[j]=a[j]-a[i];
				a[i]=0;
			}
		}else{
			if(a[i]>a[j]){
				maxx+=a[j];
				a[i]=a[i]-a[j];
				a[j]=0;
			}else{
				maxx+=a[i];
				a[j]=a[j]-a[i];
				a[i]=0;
			}
		}
		if(k==0&&i==n/2-1){
			maxx+=min(a[n/2],max(a[i],a[j]));
		}
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

