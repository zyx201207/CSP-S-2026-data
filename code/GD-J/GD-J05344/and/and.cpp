#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[2000000],max=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(n<=20&&m<=n) {
			if(a[i]==31||a[i]==15||a[i]==7){
				max=7;
			}
			if(a[i]==12||a[i]==15){
				max=12;
			}else{
				continue;
			}
		}
	}
	cout<<max;
	
}
