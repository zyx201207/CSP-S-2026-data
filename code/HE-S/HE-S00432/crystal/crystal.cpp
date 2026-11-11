#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	int r=a[3]-a[1];
	int q=m-r;
	int y=a[1]+r;
	int e=q+a[2]-1;
	int f=0;
	for(int i=1;i<=n;i++){
		if(a[i]=a[i+1]){
			f++;
		}
	}
	cout<<f;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
