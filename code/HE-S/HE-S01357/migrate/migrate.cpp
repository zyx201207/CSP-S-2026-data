#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,sum;
	cin >>c>>t;
	for(int i=0;i<t;i++){
		int a[100005]={0};
		cin >>n>>d;
		sum=1;
		for(int j=0;j<n;j++){
			cin >>a[j];
		}
		for(int j=1;j<n;j++){
			if(abs(a[j]-a[j-1])<=d){
				sum++;
			}else{
				break;
			}
		}
		cout <<sum-3<<endl;
	}
	return 0;
}
