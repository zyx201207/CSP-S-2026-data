#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,sum;
int a[200001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		if(i==1) sum=a[i];
		else sum=sum&a[i];
	}
	if(sum==a[m]){
		cout << sum;
		return 0;
	}
	else{
		int ans=sum;
		for(int i=1;i<=m;i++){
			if(i==1) sum=a[i];
			else if(i==m) sum=sum&a[i+1];
			else sum=sum&a[i];
		}
		cout << max(ans,sum);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
