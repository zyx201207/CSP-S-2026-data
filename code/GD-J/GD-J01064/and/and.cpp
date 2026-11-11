#include<bits/stdc++.h>
using namespace std;
int zjz2(int x){
	int j=1,t=x,y[15],z=0;
	while(t!=0){
		y[j]=t%2;
		t/=2;
		j++;
	}
	j--;
	for(int i=j;i>=1;i--){
		z=z*10+y[i];
	}
	return z;
} 
int zjz10(int x){
	int j=1,t=x,y[15],z=0,s=1;
	while(t!=0){
		y[j]=t%10;
		t/=10;
		j++;
	}
	j--;
	for(int i=1;i<=j;i++){
		z+=y[i]*s; 
		s*=2;
	}
	return z;
	
}
int f(int x,int y){
	int t1=zjz2(x),t2=zjz2(y),l[15],j=1,z=0;
	
	while(!(t1==0&&t2==0)){
		if(t1%10==1&&t2%10==1)l[j]=1;
		else l[j]=0;
		t1/=10;
		t2/=10;
		j++;
	}
	j--;
	for(int i=j;i>=1;i--){
		z=z*10+l[i];
	}
	return zjz10(z);
}
int n,m,a[200005],s,ma=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-m+1;i++){
		s=a[i];
		for(int j=i;j<=m+i-1;j++){
			s=f(s,a[j]);
		}
		ma=max(ma,s);
	}
	cout<<ma;
	return 0;
}

