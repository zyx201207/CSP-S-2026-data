#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int o=0;
int j=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]%2==0){
			o++;
		}else{
			j++;
		}
		if(a[i]!=i-1){
			f=0;
		}
	}
	if(f==1&&m<=n/2){
		cout<<1;
		return 0;
	}else if(f==1&&m>n/2){
		cout<<0;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
