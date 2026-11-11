//GZ-S00329 何子文 遵义市第二中学 
#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];

int shulie(long long n1,long long m1,int cha){
	int c=0;
	long long m2=0;//1,1+2,1+2+3向下取整
	
	for(int j=cha;j<=m1/2+10;j+=cha){
		m2+=j;
		c++;
		if(m2>m1){
			return c;
		}
	}
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int b=1,c=0,chaz=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+0,a+n+1);
	
	for(int i=1;i<n-1;i++){
		if(a[i+1]-a[i]!=a[i+2]-a[i+1]){
			c=1;
			break;
		}
	}
	
	if(c==0){//等差数列 包括a[i]=i
		cout<<shulie(n,m,a[2]-a[1]);
		return 0;
	}
	
	if(m!=m/2*2){
		cout<<m/2+1;
	}else{
		cout<<m/2;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

