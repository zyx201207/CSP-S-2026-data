#include<bits\stdc++.h>
using namespace std;
int n,m,a[101],c;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(m<0){
				break;
			}
			m-=a[j];
			c++;
			if(m<0){
				break;
			}
		}
	}
	if(a[1]<0){
		cout<<c-1;
	}else{
		cout<<c;
	}
	return 0;
}
