#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10; 
long long n,a[N],sum;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,j=n;
	while(1){
		if(i>j){
			cout<<sum;
			return 0;
		}
		if(c[i]==c[j]){
			if(a[i]>=a[j]){
				a[i]-=a[j],a[j]=0,j--;			
			}else{
				a[j]-=a[i],a[i]=0,i++;		
			}
		}
		else if(c[i]!=c[j]){
			if(a[i]>=a[j]){
				sum+=a[j],a[i]-=a[j],a[j]=0,j--;	
			}else{
				sum+=a[i],a[j]-=a[i],a[i]=0,i++;	
			}
		}
	}
	cout<<sum;
	return 0;
}



