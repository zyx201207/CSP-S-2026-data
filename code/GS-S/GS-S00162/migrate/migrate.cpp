#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
void input(long long*,int);
int count(int,int);
int solve(long long*,int,int); 
long long l[1000];
int answer_[50001];
int main(){
	long long c,t,n,d;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		input(l,n);
		answer_[i]=solve(l,n,d);	
	}
	for(int i=0;i<t;i++)cout<<answer_[i]<<endl;
	return 0;
}
void input(long long* L,int k){
	for(int i=0;i<k;i++){
		int a=0;
		cin>>a;
		L[i]=a;
	}
}
int count(int cha,int d){
	int answer=0;
	int min;
	if(cha<=d)return 1;
	else if(cha%d!=0)min=cha/d+1;
	else if(cha%d==0)min=cha/d;
	for(int i=0;i<=d;i++){
		for(int j=abs(d-i);j<=d;j++){
			for(int k=0;k<=min;k++){
				if(k*i+(min-k)*j==cha){
				answer++;
				}
			}
		}
	}

	return answer;
}
int solve(long long* l,int n,int d){
	int answer=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int cha=abs(l[i]-l[j]);
			if(count(cha,d)==2)answer++;
		}
	}
	return answer;
}

