#include<bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,s=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			b[s]=a[i]&a[j];
			s++;
		}	
	}	
	sort(b,b+s,cmp);
	cout<<b[0];
}
