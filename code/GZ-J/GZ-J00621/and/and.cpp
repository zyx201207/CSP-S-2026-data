#include<bits/stdc++.h>
using namespace std;
int n,m;long long a[10005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	int min=a[1];
	/*for(int i=1;i<=n;i++){
		for(int j=128;j>=1;j/=2){
			int p=1;
			b[i][p]+=a[i]-a[i]%j;
			p+=1;
		}
	}*/
	for(int i=2;i<=n;i++){
		if(a[i]<min) min=a[i];
	}
	cout<<min;
	//fclose(stdin,stdout);
	return 0;
}
