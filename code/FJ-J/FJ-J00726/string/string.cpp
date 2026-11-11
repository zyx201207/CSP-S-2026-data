#include<bits/stdc++.h>
int namespace std;
string c,b;
int main(){
	int n,a[200005],z=0;
	freopen("travel",r,"travel.in",stdin);
	freopen("travel",w,"travel.out",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b;
		for(int j=1;j<=a[i];j++){
			c+=b;
		}
	}
	for(int i=1;i<=n+1/2;i++){
		if(c[i]!=c[n-i+1]){
			z++;
		}
	}
	cout<<z;
	return 0;
}
