#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005];
char x[200005];
int sum;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>x[i];
	}
	for(int i=1,j=n;i<j;){
		if(a[i]<=a[j]){
			if(x[i]==x[j]){
				a[j]-=a[i];
				i++;
			}
			else{
				a[j]-=a[i];
				sum+=a[i];
				i++; 
			}
		}
		else{
			if(x[i]==x[j]){
				a[i]-=a[j];
				j--;
			}
			else{
				a[i]-=a[j];
				sum+=a[j];
				j--; 
			}
		}
	}
	cout<<sum;
	return 0;
} 
