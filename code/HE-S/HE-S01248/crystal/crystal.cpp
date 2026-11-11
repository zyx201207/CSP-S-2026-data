#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long m;
	long long a[100000000012];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int x=a[n/2];
	int c[n];
	for(int i=0;i<n;i++){
		c[i]=x-a[i];
	}
	sort(c,c+n,cmp);
	int sum=0,cm=0;
	for(int i=0;i<n;i++){
		if(cm>m){
			break;
		}
		cm+=abs(c[i]);
		c[i]=0;
		sum++;
	}
	cout<<1;
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
