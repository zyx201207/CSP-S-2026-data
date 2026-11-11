#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,m;
long long a[200005];
string b[200005]; 
int c[65];
bool d[200005];
void broke(int x){
	if(d[x]==0){
		d[x]==1;
		for(int i=0;i<b[x].size();i++){
			if(b[x][i]=='1'){
				c[i]--;
			}
		}
		b[x]="0";
	}	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=30;j>=0;j--){
			if(a[i]>=pow(2,j)){
				b[i]+="1";
				c[30-j]++;
				a[i]-=pow(2,j);
			}
			else{
				b[i]+="0";
			}
		} 
	}
	long long result=0;
	for(int i=0;i<=30;i++){
		if(c[i]>=m){
			result+=pow(2,30-i);
			for(int j=0;j<n;j++){
				if(b[j][i]=='0'){
					broke(j);
				}
			}
		}
	}
	cout<<result;
	return 0;
}
