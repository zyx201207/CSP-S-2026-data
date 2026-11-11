#include<bits/stdc++.h>
using namespace std;
int a[100005];
char b[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum=sum+a[i];
	}
	int i1=1,j1=n; 
	long long ans=0;
	for(long long i=1,j=sum;i1<=j1;i+=min(a[j1],a[i1]),j-=min(a[j1],a[i1])){
		if(a[j1]>a[i1]){
			if(b[j1]!=b[i1]){
				ans+=a[j1]-a[i1];
				a[j1]=a[j1]-a[i1];
				i1++;
			}else{
				a[j1]=a[j1]-a[i1];
				i1++;
			}
		}else if(a[j1]<a[i1]){
				if(b[j1]!=b[i1]){
					ans+=a[i1]-a[j1];
					a[i1]=a[i1]-a[j1];
					j1--;
				}else{
					a[i1]=a[i1]-a[j1];
					j1--;
				}
			}else{
				if(b[j1]!=b[i1]){
					ans+=a[i1];
					a[i1]=0;
					j1--;
					i1++;
				}else{
					a[i1]=0;
					j1--;
					i1++;
				}
			}
		}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
