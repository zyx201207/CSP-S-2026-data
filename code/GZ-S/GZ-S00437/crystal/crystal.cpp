//GZ-S00437 都匀市第一中学 周泽西 
#include<iostream>
#include<bits/stdc++.h>
#define MAXN 500007
using namespace std;
long long num[MAXN];
long long n,m;
long long exam(){
	long long para=0,para_1=1,dis_total=0,num_1=1,j_1=2;
	for(long long i=1,j;i<=n;i++){
		for(j=j_1;j<=n;j++){
			if(dis_total+(num[j]-num[j-1])*num_1<=m){
				dis_total+=(num[j]-num[j-1])*num_1;
				para_1++;
				num_1++;
			}
			else{
				j_1=j;
				break;

			}
		}
		dis_total=dis_total-num[j_1-1]+num[i];
		num_1--;
		para=max(para,para_1);
		para_1--; 
		if(n-i<=para)break;
	}
	return para;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i =1;i<=n;i++){
		cin>>num[i];

	}
	sort(num+1,num+1+n); 
	for(long long i =n;i>=1;i--){
		num[i]=num[i]-num[1];
	}

	cout<<exam();
	return 0;
	
}
