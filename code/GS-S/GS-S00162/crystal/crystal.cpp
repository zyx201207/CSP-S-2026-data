#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

int n_L[50010];
int cha[50010];
void sort(int*,int);
void input(int*,int n);
int solve(int ,int);
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n;
	cin>>m;
	input(n_L,n);
	sort(cha,n);
	cout<<solve(n,m);
	return 0;
}
void input(int* L,int n){
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		L[i]=a;
		if(i!=0)cha[i]=abs(L[i]-L[i-1]);
	}
}
void sort(int*L,int n){
	int flag=1;
	for(int i=1;i<n;i++){
		for(int j=i;j<n;j++){
			if(L[i]>L[j]){
				int tep=0;
				tep=L[i];
				L[i]=L[j];
				L[j]=tep;
				flag=0;
			}
		}
		if(flag)break;
	}
}
int solve(int n,int m){
	int answer=0;
	for(int i=1;i<n;i++){
		if(m<0)break;
		m-=cha[i];
		
		if(m>0||m==0){
		answer++;}
	}
	int flag=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j!=i&&n_L[i]==n_L[j])flag=1;
		}
	}
	return answer+flag;
}

