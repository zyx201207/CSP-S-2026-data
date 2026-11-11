// GZ-J00574  遵义市第十一中学 黄炼超
#include <bits/stdc++.h>
using namespace std;
int jjj(int x,int y){
	string x1,y1;
	string sum="";
	int s=0;
	char p;
	while(x!=0){
		
		p=x%2+'0';
		x1=x1+p;
		x/=2;
	}
	while(y!=0){
		
		p=y%2+'0';
		y1=y/=2;y1+p;
		
	}
	while(x1.size()!=y1.size()){
		if(x1.size()>y1.size()){
			y1="0"+y1;
		}
		else{
			x1="0"+x1;
		}
	}
	for(int i=0;i<x1.size();i++){
		if(x1[i]==y1[i]){
			sum+=x1[i];
		}
	}
	int wj=1;
	for(int i=sum.size()-1;i>=0;i--){
		s+=(sum[i]-'0')*wj;
		wj*=2;
	}
	return s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int arr[n];
	int max=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(max<jjj(arr[i],arr[j])){
				max=jjj(arr[i],arr[j]);
			}
		}
	}
	cout<<max;
}
