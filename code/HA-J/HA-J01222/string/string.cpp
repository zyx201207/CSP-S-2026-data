#include <bits/stdc++.h>
using namespace std;
int a[10010];
char b[10010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int f1=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[n-1]){
			f1++;
			break;
		}
		
	}
	int f2=0;
	for(int i=1;i<=n;i++){
		if(b[i]!=b[n-1]){
			f2++;
			break;
		}
		
	}
	if(f1==0||f2==0){
		cout<<0;
		return 0;
	}
	return 0;
}
