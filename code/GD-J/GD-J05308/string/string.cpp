#include<iostream>
#include<cstring>
using namespace std;
int n;
long long xi[200002];
char c[200002];
long long sum,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>xi[i]>>c[i];
		sum+=xi[i];
	}
	//Ë«Ïòcomp 
	for(int i=1;i<=n/2;i++){
		long long nxl=min(xi[i],xi[n-i+1]);
		if(c[i]!=c[n-i+1]){
			ans+=xi[i]; 
		}
	}
	cout<<sum/2;
	return 0;
} 
