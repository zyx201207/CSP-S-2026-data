#include <bits/stdc++.h>
using namespace std;
int main () {
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int n,m;
cin>>n>>m;
int a[100005]={};
for(int i=0;i<n;i++){
	cin>>a[i];

}

sort(a,a+n);

int b=0;
for(int i=0;i<n;i++){
	int cnt=1;
	for(int j=0;j<n;j++){
		if(abs(a[i]-a[j])<=m and i!=j){
			m=m-abs(a[i]-a[j]);
			cnt++;
			
		}	
	}
	if(cnt>b){
		b=cnt;	
	}
}
	
cout<<b;
return 0;
}
