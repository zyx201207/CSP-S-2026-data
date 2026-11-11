#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
long long a[100007];//,d[40]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
//long long c;
//string b[50];
//string x,y;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	cout<<a[m-1];
	/*int j=0;
	int maxn=0,ma=0;
	for(int i=0;i<=m;i++){
		while(a[i]!=0){
			b[i][j]=a[i]%2+'0';
			a[i]=a[i]/2;
			j++;
			maxn++;
			//cout<<b[i][j];
		}
		cout<<endl;
		if(maxn>ma){
			ma=maxn;
		}
		j=0;
		maxn=0;
	}
	for(int s=0;s<ma;s++){
			y[s]='1';
	}
	for(int k=0;k<m;k++){
		for(int q=0;q<ma;q++){
			if(y[ma]=='1'||b[k][ma]=='1'){
				y[ma]='1';
			}
			else y[ma]='0';
		}
		if(y>x){
			x=y;
		}
		cout<<y;
		for(int s=0;s<ma;s++){
			y[s]='1';
		}
	}
	cout<<x;
	long long sum=0;
	for(int i=ma;i>0;i--){
		sum=sum+x[i]*d[i-ma];
	}
	cout<<sum;*/
	return 0;
}
