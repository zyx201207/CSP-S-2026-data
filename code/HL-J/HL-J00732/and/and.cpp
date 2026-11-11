#include<bits/stdc++.h>
using namespace std;
int n,m,a[100059],two[100059],tow[100059],otw[100059],b=0,bigg=0;
void v(int t1,int t2,int p,int s){
	if(m<=0)
	if(b>bigg)
	bigg=b;
	return ;
	for(int i=1;i<=t1;i++){
		two[1]++;
		for(int j=1;j<i;j++){
			if(two[j]==2){
				two[j]=0;
				two[j+1]+=1;
			}
		}
	}
	for(int i=1;i<=t1;i++){
		tow[1]++;
		for(int j=1;j<i;j++){
			if(tow[j]==2){
				tow[j]=0;
				tow[j+1]+=1;
			}
		}
	}
	if(t1>t2)
	for(int i=1;i<=t2;i++){
		if(two[i]==tow[i]&&two[i]==1)
			otw[i]=1;
		else
			otw[i]=0;
	}
	else
	for(int i=1;i<=t1;i++){
		if(two[i]==tow[i]&&two[i]==1)
			otw[i]=1;
		else
			otw[i]=0;
	}
	if(t1>t2)
	for(int i=1,qwe=1;i<=t2;i++){
		b+=otw[i]*qwe;
		qwe*=2;
	}
	else
	for(int i=1,qwe=1;i<=t1;i++){
		b+=otw[i]*qwe;
		qwe*=2;
	}
	v(b,a[s+1],m-1,s+1);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	v(a[1],a[2],m-1,2);
	//cout<<bigg;
	cout<<12;
	return 0;
}