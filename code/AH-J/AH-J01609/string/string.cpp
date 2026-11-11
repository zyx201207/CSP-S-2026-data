#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	int j=n;
	long long sum=0;
	for(int i=1;i<j;){
		if(b[i]!=b[j]){
			if(a[i]<a[j]){
				sum+=a[i];
				a[j]-=a[i];
				i++;
			}else{
				sum+=a[j];
				a[i]-=a[j];
				j--;
			}
		}else{
			if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else{
				a[i]-=a[j];
				j--;
			}
		}
	}
	cout<<sum;
	return 0;
}
