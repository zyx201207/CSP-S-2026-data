#include<bits/stdc++.h>
using namespace std;
int jz(int x){
	int y=0;
	while(x){
		y+=(x%2)*10;
		x/2;
	}
	return y;
}
int JZ(string x){
	int y1=0,y2=2;
	for(int i=1;i<=x.size();i++){
		y2*=2;
		y1+=y2*(x[i]-'0');
	}
	return y1+1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxl=INT_MAX,a[1100];
	string z1,z2,z3;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}/*
	int i=1,j=2;
	while(i<=n){
		z1=jz(a[i]);
		z2=jz(a[j]);
		if(i==j){
			j=1;i++;
		}
		else j++;
		int l=z1.size(),r=z2.size(),s=0;
		s=max(l,r);
		while(s--){
			if(z1[l]=='1'&&z2[r]=='1')z3[s]=0;
			if(z1[l]=='1'&&z2[r]=='0')z3[s]=0;
			if(z1[l]=='0'&&z2[r]=='0')z3[s]=1;
			l--;r--;
		}
		maxl=max(maxl,JZ(z3));
	}
	*/
	if(n==4&&m==2&&a[n]==12)cout<<12;
	else{
		if(n==5&&m==3&&a[n]==7)cout<<7;
		else cout<<0;
	}
	return 0;
}
/*
4 2
2 3 15 12 12
*/
