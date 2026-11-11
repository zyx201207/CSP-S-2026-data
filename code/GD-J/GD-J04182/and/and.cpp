#include<bits/stdc++.h> 
using namespace std;
int a[10010];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
    if(m==1){
    	int max=0;
    	for(int i=1;i<=n;i++){
    	if(i==1){
    		max=a[i];
		}
		if(a[i]>max){
			max=a[i];
		}
	}
	cout<<max<<endl;
	}else if(m==n-1){
		int min=0;
    	for(int i=1;i<=n;i++){
    	if(i==1){
    		min=a[i];
		}
		if(a[i]<min){
			min=a[i];
		}
	}
	int min1=100;
    for(int i=1;i<=n;i++){
    	if(i==1){
    		min1=a[i];
		}
		if(a[i]<min1&&a[i]>min){
			min1=a[i];
		}
	}
	cout<<min1<<endl;
	}else if(m==n){
		int min2=0;
    	for(int i=1;i<=n;i++){
    	if(i==1){
    		min2=a[i];
		}
		if(a[i]<min2){
			min2=a[i];
		}
	}
	cout<<min2<<endl;
	}else{
		cout<<endl;
	}
	
	return 0;
}
