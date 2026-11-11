#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010],b[100010],c,d,e=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	for(int r=0;r<m;r++){
		cin>>c>>d;
		for(int i=0;i<c;i++){
		cin>>a[i];
		if(i>=1&&a[i]-a[i-1]<=d){
			if(i>=d) {
				for(int j=0;j<c;j++){
					if((a[i]-a[j])%d==1&&(a[i]-a[j])>d) e++; 
			}
		}
	}}
		
	cout<<e-1<<" ";
	e=0;
	}
	
	
	return 0;
	
}
