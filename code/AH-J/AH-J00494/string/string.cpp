#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],cnt=0;
char c[200010];
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n,suml=a[1],sumr=a[n];
	while(l<=r){
		if(c[l]!=c[r]){
			if(suml<sumr){
				sum+=suml;
				sumr-=suml;
				l++;
				suml=a[l];
			}
			else if(suml>sumr){
				sum+=sumr;
				suml-=sumr;
				r--;
				sumr=a[r];
			}
			else if(suml==sumr){
				sum+=suml;
				l++;
				suml=a[l];
				r--;
				sumr=a[r];
			}
		}
		else{
			if(suml<sumr){
				sumr-=suml;
				l++;
				suml=a[l];
			}
			else if(suml>sumr){
				suml-=sumr;
				r--;
				sumr=a[r];
			}
			else if(suml==sumr){
				l++;
				suml=a[l];
				r--;
				sumr=a[r];
			}
		}
	}
	cout<<sum;		
	return 0;
}
