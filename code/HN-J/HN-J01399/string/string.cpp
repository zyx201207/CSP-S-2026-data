#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[510000];
char op[510000];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>op[i];
	}
	int ans=0;
	int i=1,j=n;
	while(i<=j){
		if(op[i]==op[j]){
			if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}
			else if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			} 
			else if(a[i]==a[j]){
				i++;
				j--;
			}
		}
		else {
			if(a[i]<a[j]){
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}
			else if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				j--;
			} 
			else if(a[i]==a[j]){
				ans+=a[i];
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*6
 1000000000 a
 1000000000 a
 1000000000 a
 1000000000 b
 1000000000 b
 1000000000 b
 
 3
 2 a
 2 b
 1 c*/
