#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],sum;
char c[200005];
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int j=n;
	for(int i=1;i<=ceil(n*1.0/2);){
		if(a[i]!=a[j]){
			if(c[i]!=c[j]){
				if(a[i]>a[j]){
					sum+=a[j];
					a[i]-=a[j];
					j--;
				}
				else{
					sum+=a[i];
					a[j]-=a[i];
					i++;	
				}
			}
			else{
				if(a[i]>a[j]){
					a[i]-=a[j];
					j--;
				}
				else{			
					a[j]-=a[i];
					i++;	
				}
			}
		}
		else{
			if(c[i]!=c[j]){
				sum+=a[i];
			}
			i++;
			j--;
		}
	}
	cout<<sum;
	return 0;
} 
