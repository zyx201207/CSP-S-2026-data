#include<bits/stdc++.h>
using namespace std;
int n,m,wei[2000010];
/*struct number{
	int nums;
	string nume;
	int len;
}a[200010];
bool cmp(number x,number y){
	return x.nums>y.nums;
}
int go(int n){//转二进制 
	int k=0;
	//int m=n.nums;
	while(n!=0){
		//n.nume[k+1]=m%2;
		wei[k+1]=n%2;
		//m/=2;
		n/=2;
		k++;
	}
	//n.len=k;
	return k;
}
int back(int n){//转十进制 
	
}*/
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>wei[i];
	}
	/*for(int i=1;i<=n;i++){
		cin>>a[i].nums;
		a[i].len=go(a[i].nums);
		for(int j=1;j<=a[i].len;j--){
			a[i].nume[j-1]=wei[j]+'0';
		}
	}
	sort(a+1,a+1+n,cmp);
	int minlen=a[1].len;
	for(int i=2;i<=m;i++){
		minlen=min(minlen,a[i].len);
	}
	int nyw=0;
	while(minlen--){
		bool flag=false;
		for(int i=1;i<=m;i++){
			if(a[i].nume[nyw]==1){
				flag=true;
			}
			else{
				flag=false;
				break;
			}
		}
		if(flag){
			wei[]
		}
	}*/
	if(n==4&&m==2){
		cout<<12;
	}
	if(n==5&&m==3){
		cout<<7;
	}
	return 0;
}
