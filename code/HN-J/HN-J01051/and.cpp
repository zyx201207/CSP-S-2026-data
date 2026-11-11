#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+1+n,cmp);
	if(m==2){
		for(int i=1;i<=m;i++){
			if((a[i]&a[i+1])==0){
				m++;
			}	
		}
	}
	cout<<a[m];
	

	
	return 0;
}
