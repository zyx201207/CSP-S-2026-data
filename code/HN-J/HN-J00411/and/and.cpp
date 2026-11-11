#include<bits/stdc++.h>
using namespace std;
int a[20010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int max=0;
	for(int i=1;i<=n;i++){
		for(int j=1+i;j<=n;j++){
			int b=a[i]&a[j];
			if(b>=max){
				max=b;
			}
		}
	}
	
	cout<<max;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
