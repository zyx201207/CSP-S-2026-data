#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d %c",a+i,c+i);
	for(int i=1;i<=n;){
		for(int j=n;j>=1;){
			if(i>=j){
				cout<<ans;
				return 0;
			}
			if(a[i]>a[j]){
				a[i]-=a[j];
				if(c[i]!=c[j]){
					ans+=a[j];
				}
				j--;
			}
			else if(a[i]<a[j]){
				a[j]-=a[i];
				if(c[i]!=c[j]){
					ans+=a[i];
				}
				i++;
			}
			else{
				if(c[i]!=c[j]){
					ans+=a[i];
				}
				i++,j--;
			}
		}
	}
}
