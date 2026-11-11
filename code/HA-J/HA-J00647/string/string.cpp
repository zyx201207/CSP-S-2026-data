#include<bits/stdc++.h>
using namespace std;
long long n,len,ans;
long long a[200005];//Ã¿¸ö×ÖÄ¸Êý 
bool b[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	for(int i=1,j=n;i<=n,j>=1;){
		if(i>=j){
			break;
		}
//		cout<<a[i]<<" "<<a[j]<<' '<<c[i]<<" "<<c[j]<<" "<<ans<<endl;
		if(c[i]!=c[j]){
			if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}
			else if(a[i]<a[j]){
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}
			else{
				ans+=a[i];
				i++;
				j--;
				
			}
		}
		else{
			if(a[i]>a[j]){
				
				a[i]-=a[j];
				j--;
			}
			else if(a[i]<a[j]){
				
				a[j]-=a[i];
				i++;
			}
			else{
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
