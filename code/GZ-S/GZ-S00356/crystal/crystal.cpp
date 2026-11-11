//GZ-S00356，邱伟轩，贵阳市乌当第二中学
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int e[n];
	for(int i=0;i<n;i++){
		cin>>e[i];
	}
	sort(e,e+n+1);
	int num=0; 
	if(m!=0){
	int min_sub=-1;
	for(int i=0;i<n;i++){
		int s=0;
		for(int j=0;j<i;j++){
			if(i==j)continue;
			s+=abs(e[i]-e[j]);
		}
		if(s<=m){	
			min_sub=i;	
		}
	}
	for(int i=1;i<=min_sub;i++){
		while(e[i]<e[min_sub+1]){
			e[i]++;
			m--;
		}
	}
	for(int i=1;i<=n;i++){
		if(e[i]==e[min_sub]){
			num++;
		}
	}}
	else {
		for(int i=0;i<n;i++){
			int max_num=0;
			for(int j=0;j<n;j++){
				if(e[j]==e[i])max_num++;
			}
			num=max(max_num,num);
		}
	}
	cout<<num;
	return 0;
} 
