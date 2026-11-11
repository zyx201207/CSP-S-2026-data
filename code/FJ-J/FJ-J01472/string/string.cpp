#include<bits/stdc++.h>
using namespace std;
char m[1000005];
long long n,a[1000005],b,ans,sum,mn,o,p;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	cin>>m[i];
    	ans+=a[i];
	}
	if(ans%2==1){
		ans/=2;
		ans+=1; 
	}
	else {
		ans/=2;
	}
	for(int i=1;i<=n;i++){
		mn+=a[i];
		if(mn>=ans){
			p=mn-ans;
		    o=i;
			break;	
		}
	}
	long long i=1,j=n;
	while(i<=j){
		if(a[i]>=a[j]){
			if(m[i]!=m[j]){
				sum+=a[j];
			}
			a[i]-=a[j];
			j--;
		}
		if(a[i]<a[j]){
			if(m[i]!=m[j]){
				sum+=a[i];
			}
			a[j]-=a[i];
			i++;
		}
		if(i==o){
			if(m[i]!=m[j]){
				sum+=a[j];
			}
			break;
		}
		if(j==o){
			if(m[i]!=m[j]){
				sum+=a[i];
			}
			break;
		}
	}
	cout<<sum;
	return 0;
} 
