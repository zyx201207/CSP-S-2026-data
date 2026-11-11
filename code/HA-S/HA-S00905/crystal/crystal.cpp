#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
sort(a+1,a+1+n);
int b[100005];
for(int i=1;i<=n;i++){

	b[i]=a[i+1]-a[i];

}
sort(b+1,b+n);
int cnt=0;
for(int i=1;i<=n;i++){
	if(b[i]>m){
		cout<<0;
		return 0;
	}
}


for(int i=1;i<=n;i++){
	
	if(b[i]<=m){
		cnt++;
		if(a[i]>0){
			m-=b[i];
		}
		else{
			m+=b[i];
		}
	}
	else{
		break;
	}
}

cout<<cnt;
	return 0;
} 
