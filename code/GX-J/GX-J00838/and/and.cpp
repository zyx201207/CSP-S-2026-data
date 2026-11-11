#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],s[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("ans,out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ff=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int f=0;
		for(int j=0;pow(2,j)-1<=a[i];j++){
			if(pow(2,j)-1==a[i]){
				f=1;
				//cout<<pow(2,j);
			}
		}
		if(f==0){
			ff=0;
		}
	}
	//cout<<ff<<endl;
	if(ff==1){
		sort(a+1,a+1+n);
		int k=1;
		while(a[2]!=0){
			s[k]=a[2]%2;
			a[2]/=2;
			k++;
		}
		int sum=0;
		for(int i=k;i>=1;i--){
			sum+=s[i]*pow(10,k-i-1);
			//cout<<pow(10,k-i);
		}
		cout<<sum;
	}else if(pow(2,i)==n){
		if(n==2){
			cout<<"0";
			return 0;
		}
		for(int i=1;pow(2,i)<=n;i++){
			if(pow(2,i)==n){
				for(int j=1;j<=i;j++){
					cout<<"1";
				}
			}
	}else{
		int i=1,kk=0;
		while(a[1]!=0){
			s[i]=a[1]%2;
			a[1]/=2;
			kk++;
		}
		for(int j=kk;j>=1;j--){
			cout<<s[j];
		}
	}
	return 0;
}
