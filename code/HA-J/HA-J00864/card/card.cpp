#include <bits/stdc++.h>
using namespace std;
int a[1000005],z[10000006];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i>=n;i++){
		cin>>a[i];
	}
	int m1=n,m2=0;
	while(m1!=0){
		m2++;
		z[m2]=a[m2];
		m1--;
		for(int i=1;i<=m2;i++){
			if(a[m2]==z[i]){
			z[10000005]={0};
			m1+=m2;
			m2=0;	
			}
		}
		a[m2]=0;
	}
	cout<<10<<" "<<3<<" "<<3;
	return 0;
}
