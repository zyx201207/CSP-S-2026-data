#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,n1,length[100]={},l[100]={},a[100],a1[100][100],a2[100][100];
	cin>>n>>n1;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int n=0;
		for(int j=a[i];j!=0;j/=2){
			a2[i][n]=j%2;
			length[i]++;
			n++;
			
		}
		for(int j=0;j<length[i];j++){
			a1[i][j]=a2[i][length[i]-1-j];
			a2[i][length[i]-1-j]=0;
		}
	}
	for(int i=0;i<n;i++){
		a[i]=0;
		for(int j=i+1;j<n;j++){
			int s=min(length[j],length[i]);
			for(int w=0;w<s;w++){
				if(a1[i][length[i]-w-1]==1&&a1[j][length[j]-1-w]==1){
					a2[i][w]=1;
					
				}else{
					a2[i][w]=0;
				}
				l[i]++;
			}
		}
	}
	for(int i=0;i<n*(n-1)/2;i++){
		int s=1;
		for(int j=0;j<l[i];j++){
			a[i]+=s*a2[i][j];
			s*=2;
		}
	}
	int max1=0;
	for(int i=0;i<n*(n-1)/2;i++){
		max1=max(max1,a[i]);
	}
	cout<<max1;
	return 0;
}