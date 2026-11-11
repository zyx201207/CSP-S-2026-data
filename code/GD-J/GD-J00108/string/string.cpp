#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum=0;
char c[200005];
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<=j;){
		if(a[i]==a[j]){
			if(c[i]==c[j]){
				i++,j--;
			}
			else{
				sum+=a[i];
				i++,j--;
			}
		}
		else{
			if(a[i]>a[j]){
				if(c[i]==c[j]){
					a[i]-=a[j];
					j--;
				}
				else{
					sum+=a[j];
					
					a[i]-=a[j];
					j--;
				}
			}
			else{
				if(c[i]==c[j]){
					a[j]-=a[i];
					i++;
				}
				else{
					sum+=a[i];
					
					a[j]-=a[i];
					i++;
				}
			}
		}
	}
	cout<<sum<<endl;
	
	return 0;
} 
