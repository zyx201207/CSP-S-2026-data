#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	long long sum=0,i=1,j=n;
	while(i<=j){
		if(c[i]==c[j]){
			if(a[i]==a[j])i++,j--;
			else if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else{
				a[j]-=a[i];
				i++;
			}
		}else{
			if(a[i]==a[j]){
				sum+=a[i];
				i++;
				j--;
			}else{
				if(a[i]>a[j]){
					sum+=a[j];
					a[i]-=a[j];
					j--;
				}else{
					sum+=a[i];
					a[j]-=a[i];
					i++;
				}
			}
		}
	}
	cout<<sum;
	return 0;
} 
