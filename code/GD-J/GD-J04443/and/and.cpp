#include<iostream>
using namespace std;
int main(){
	//freopen("and.in" "r" stdin);
	//freopen("and.out" "r" stdout);
	long long max=-10e5;
	int a[1000000];
	long long n;
	long long m;
	cin>>n;
	cin>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<=n;j++){
			if(a[i]&&a[j]>max){
				max=a[i]&&a[j];
			}		}		
	}
	cout<<max;
}

