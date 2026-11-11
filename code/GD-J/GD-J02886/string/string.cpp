#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	unsigned long long n,a[200010],sum=0,f=0,num=0,t=0,x=0,y;
	string s;
	char c[200010];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
	}
	if(n%2==0){
		y=n/2;
	}
	else{
		y=n/2+1;
	}
	for(int i=1,j=n;i<=n/2-t,j>=n/2+x;i++,j--){
		if(c[i]!=c[j]){
			f=1;
			if(a[i]!=a[j]){
				if(a[i]>a[j]){
					sum+=a[i]-a[j];
				}
				else{
					sum+=a[j]-a[i];
				}
			}
			else{
				sum+=a[i];
			}
		}
		else{
			if(a[i]!=a[j]){
				f=1;
				if(a[i]>a[j]){
					a[i]-=a[j];
					i--;
					t++;
					
				}
				else{
					a[j]-=a[i];
					j++;
					x++;
				}
			}
			else{
				f=1;
			}
		}
	}
	if(f=0){
		cout<<0;
		return 0;
	}
	cout<<sum;
	return 0;
}
