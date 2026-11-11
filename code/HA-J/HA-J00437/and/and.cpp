#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10; 
long long a[N];
long long n,m;
int MAX=INT_MIN;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n]<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long c=a[i]&a[j];
			if(c>MAX&&i!=j){
				MAX=a[i]&a[j];
			}	
		}
	}
	cout<<MAX<<endl;
	return 0;
} 


