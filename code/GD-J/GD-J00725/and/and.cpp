#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	int n, m;
	cin >>n >>m;
	for(int i=0;i<n;i++){
		cin >>a[i];
	}
	if(m==1){
		int max1=-1;
		for(int i=0;i<n;i++){
			max1=max(max1,a[i]);
		}
		cout <<max1;
		return 0;
	}
	else if(m==2){
		int max1=-1;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				int s=a[i];
				s&=a[j];
				max1=max(max1,s);
			}
		}
		cout <<max1;
		return 0;
	}
	else if(m==n){
		int sum=a[0];
		for(int i=1;i<n;i++){
			sum&=a[i];
		}
		cout <<sum;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
