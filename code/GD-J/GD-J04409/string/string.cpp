#include<bits/stdc++.h>
using namespace std;
char b[2200000],y;
long long a[2200000],x=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0,box=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
		for(long long i=1;i<=n;i++){
			ans=0;
				while(a[i]>0){
					//cout<<1;
					if(b[i]!=b[n-i+1-ans]&&a[i]>=a[n-i+1-ans]){//字符不等 a>b; 
						box=box+a[n-i+1-ans];
						a[i]=a[i]-a[n-i+1-ans];
						a[n-i+1-ans]=0;
						x=a[i];
						y=b[i];
						ans++;
					}
					if(b[i]==b[n-i+1-ans]&&a[i]>=a[n-i+1-ans]){//字符等 a>b; 
						a[i]=a[i]-a[n-i+1-ans];
						a[n-i+1-ans]=0;
						x=a[i];
						y=b[i];
						ans++;
					}
					if(b[i]!=b[n-i+1-ans]&&a[i]<=a[n-i+1-ans]){//字符不等 a<b; 
						box=box+a[i];
						a[n-i+1-ans]=a[n-i+1-ans]-a[i];
						a[i]=0;
						x=a[n-i+1-ans];
						y=b[n-i+1-ans];
						break;
					}
					if(b[i]==b[n-i+1-ans]&&a[i]<=a[n-i+1-ans]){//字符等 a<b; 
						a[n-i+1-ans]=a[n-i+1-ans]-a[i];
						a[i]=0;
						x=a[n-i+1-ans];
						y=b[n-i+1-ans];
						break;
					}
					if(n-i+1-ans<=i){
						break;
					}
				}
	}
	if(y!=b[n/2+1]){
			if(x<=a[n/2+1]){
				box=box+x;
			}
			else if(x>=a[n/2+1]){
				box=box+a[n/2+1];
			}
	}
	else if(y!=b[n/2]){
			if(x<=a[n/2]){
				box=box+x;
			}
			else if(x>=a[n/2]){
				box=box+a[n/2];
			}
	}
		cout<<box;
	return 0;
}
