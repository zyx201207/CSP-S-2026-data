#include<iostream>
using namespace std;
int a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	} 
	long long ans=0;
	int i=1,j=n;
	while(i<j){
		if(c[i]==c[j]&&a[i]==a[j]){
			i++;
			j--;
		}
		else if(c[i]==c[j]&&a[i]!=a[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}
			else{
				a[j]-=a[i];
				i++;
			}
		}
		else if(c[i]!=c[j]&&a[i]==a[j]){
			ans+=a[i];
			i++;
			j--;
		}
		else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				ans+=a[j];
				j--;
			}
			else{
				a[j]-=a[i];
				ans+=a[i];
				i++;
			}
		}
	}
	cout<<ans; 
	return 0;
}
