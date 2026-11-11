// Gz-J00230 黔西市思源实验学校 许邴淳
#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	int sum;
	int b[sum];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
		b[sum]=a[i]&a[j];
		sum++;
	}
	}
	int max=b[0];
	for(int i=1;i<sum;i++){
		if(b[i]>max){
			max=b[i];
		}
	}
	cout<<max;
	fclose(stdin);
	fclose(stdout);
    return 0;
} 
