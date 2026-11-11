#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long i=1,j=n;
	while(i<=j){
		if(c[i]==c[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				a[j]=0;
				j--;
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				a[i]=0;
				i++;
			}else{
				a[i]=0;
				a[j]=0;
				i++;
				j--;
			}
		}else{
			if(a[i]>a[j]){
				//cout<<i<<" "<<j<<endl;
				ans+=a[j];
				a[i]-=a[j];
				a[j]=0;
				j--;
				
			}else if(a[i]<a[j]){
				//cout<<i<<" "<<j<<endl;
				ans+=a[i];
				a[j]-=a[i];
				a[i]=0;
				i++;
				
			}else{
				//cout<<i<<" "<<j<<endl;
				ans+=a[i];
				a[i]=0;
				a[j]=0;
				i++;
				j--;
			}
			
		}
	}
	cout<<ans;
	return 0;
}
