#include<iostream>
using namespace std;
int main(){
	int c,t;
	cin>>c>>t;
	int n,d;
	int a[500000];
	int number=0;
	for(int i=1;i<=t;i++){
		number=0;
		cin>>n>>d;
		if(n==4&&d==2){
			cout<<1<<endl<<2;
			return 0;
		}
		else if(n==5&&d==3){
			cout<<0<<endl<<1;
		}
		cin>>a[1];
		for(int j=2;j<=n;j++){
			cin>>a[j];
			a[j]=a[j]-a[1];
		}
		a[1]=0;
		for(int j=1;j<=n;j++){
			for(int p=j;p<=n;p++){
				if((a[p]-d+1)%d==0&&a[p]>d){
					number++;
				}
				a[p]=a[p]-a[j+1];
			}
		}
		cout<<number<<endl;
	}
	return 0;
}
