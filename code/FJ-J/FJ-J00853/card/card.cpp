#include<bits/stdc++.h>
using namespace std;
long long n,m,m1,m2,a[10000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1){
		cout<<1;
		return 0;
	}
	else if(n==2){
		if(a[1]!=a[2]){
			if(a[1]==1) m1++;
			if(a[1]==2) m2++;
			if(a[2]==1) m1+=2;
			if(a[2]==2) m2+=2£» 
		}
		else{
			if(a[2]==1) m1+=2;
			else if(a[2]==2) m2+=2;
		} 
		cout<<m1<<m2;
	}
	return 0;
}
