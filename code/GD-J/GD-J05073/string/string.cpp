#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n+1];
	string b[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int sum=0;
	int i=1,j=n;
	while(i<=j){
		int h= min(a[i],a[j]);
		if(b[i]!=b[j]){
			sum=sum+h;
			if(a[i]>a[j]){
			j--;
			a[i]=a[i]-a[j];
		}else if(a[i]==a[j]){
			i++;
			j--;
		}else{
			i++;
			a[j]=a[j]-a[i];
		}
			}else{
				if(a[i]>a[j]){
			j--;
			a[i]=a[i]-a[j];
		}else if(a[i]==a[j]){
			i++;
			j--;
		}else{
			i++;
			a[j]=a[j]-a[i];
		}
			}
		
				
		
		}

	cout<<sum;
	return 0;
}
