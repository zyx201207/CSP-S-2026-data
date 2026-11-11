#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200010];
long long s[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	if(m==1) cout<<a[n];
	if(m==n){
		int t=a[1];
		for(int i=2;i<=n;i++){
			t&=a[i];
		}
		cout<<t;
	}
	if(m==2){
		int t=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				s[t]=a[i]&a[j]; 
				//cout<<a[i]<<"   "<<a[j]<<"   "<<(a[i]&a[j])<<"   "<<s[t]<<endl;
			}
		}
		cout<<s[t];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
