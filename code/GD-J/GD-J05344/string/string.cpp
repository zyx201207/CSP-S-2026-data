#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,a;
	cin>>n;
	char c;
	string chuan;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		while(a>0){
			a--;
			chuan+=c;
		}
	}
	int l=0,r=chuan.size();
	int mid=(l+r)/2;
while(l<r){	
	if(l==mid||r==mid){
		break;
	}
	if(chuan[l]!=chuan[r]){
		chuan[r]=chuan[l];
		cnt++;
	}
	l++;
	r--;
}
cout<<cnt;		
	
	}
	
