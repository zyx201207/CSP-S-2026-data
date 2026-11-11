#include<bits/stdc++.h>
using namespace std;
const int M=1e5*2+10;
long long a[M];
char s[M];
int main(){
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		if(s[i]==s[i-1]){
			a[i-1]=a[i]+a[i-1];
			i--;
			n--;
		}
	}
	long long sum=0;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1,j=n;i<j;){
		if(s[i]!=s[j]){
			if(a[i]<a[j]){
				a[j]-=a[i];
				sum+=a[i];
				i++;
				continue;
			}
			if(a[i]>a[j]){
				a[i]-=a[j];
				sum+=a[j];
				j--;
				continue;
			}
			if(a[i]==a[j]){
				sum+=a[j];
				i++,j--;
				continue;
			}
		}
		else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
				continue;
			}
			if(a[j]>a[i]){
				a[j]-=a[i];
				i++;
				continue;
			}
			if(a[j]==a[i]){
				i++,j--;
				continue;
			}
		}
	}
	cout<<sum;
	return 0;
}
