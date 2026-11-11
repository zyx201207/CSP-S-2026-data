#include<bits/stdc++.h>

using namespace std;

int crystal[500001];
int power[500001];
int n,m;
int ans=0;

int atry(int nub){
	int rest1=m;
	int more=1;
	int powers=0;
	for(int i=nub-1;i>0;i--){
		powers+=power[i];
		if(rest1>=powers){
			more+=1;
			rest1-=powers;
		}
		else{
			break;
		}
	}
	return more;
}

int main(){
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>crystal[i];
	}
	for(int i=n-1;i>0;i--){
		power[i]=crystal[i+1]-crystal[i];
	}
	int ans1;
	for(int i=n;i>0;i--){
		ans1=atry(i);
		if(ans1>ans){
			ans=ans1;
		}
	}
	cout<<ans;
} 
