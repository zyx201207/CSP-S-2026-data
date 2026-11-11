#include<bits/stdc++.h>
using namespace std;
int a[10009];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,x,j=1,num=0,f=0,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<=n;i++){
		y=a[1];
		if(y!=a[i]){
			f=1;
		}
	}
	if(f==0){
		cout<<n;
	}else{
		if(n%2!=0){
			x=n/2+1;
		}else x=n/2;
		while(m!=0){
			if(a[x-j]==a[x]){
				j++; 
			}
			a[x-j]++;
			m--;
		}
		for(int i=1;i<=n;i++){
			if(a[i]==a[x]){
				num++;
			}
		}
		cout<<num;
	}
	fclose(stdin);
	fclose(stdin);
	return 0;
} 

