#include <bits/stdc++.h>
using namespace std;
int n,k,a[200005],sum,num;
int main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxx=-1;
	if (k==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(k==2){
	    for (int i=1;i<=n;i++){
		    for (int j=i+1;j<=n;j++){
			    int s=a[i]&a[j];
			    if (s>maxx){
				    maxx=s;
			    }
			    continue;
		    }
	    }
	    cout<<maxx;
	    return 0;
	}
	if (k==n){
		sum=a[1];
		for (int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	if (k==n-1){
		sum=a[1];
		num=a[2];
		for (int i=2;i<=n-1;i++){
			sum=sum&a[i];
		}
		for (int i=3;i<=n;i++){
			num=num&a[i];
		}
		cout<<max(num,sum);
		return 0;
	}
	return 0;
} 
