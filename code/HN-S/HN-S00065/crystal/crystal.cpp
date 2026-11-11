#include<bits/stdc++.h>
using namespace std;
long long a[100000];
long long b[100000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int ans=0;
	int n;
	int m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int num=n/2;
	for(int i=0;i<n;i++){
		if(a[i]==a[num]){
			ans++;
		}
	}
	for(int i=0;i<=num;i++){
		b[i]=a[num]-a[i];
		}
	sort(b,b+num-1);
	for(int i=0;i<=num;i++){
		if(m>=b[i]){
			m=m-b[i];
			ans++;
		}
	}
	cout<<ans-1;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
