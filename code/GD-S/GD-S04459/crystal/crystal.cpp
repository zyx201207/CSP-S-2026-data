#include<bits/stdc++.h>

using namespace std;
int a[500005];
int n,m;
int ww;
int tmp=0;
int searching1(int num[],int len){
	
	int maxnn=1,maxnn2=1;
	for(int i=0;i<=len;i++){
		
		if(num[i]==num[i+1]){
			maxnn2++;
		}
		if(num[i]!=num[i+1]){
			maxnn=max(maxnn,maxnn2);
			maxnn2=1;
		}
	}
	return maxnn;
}
void sea2(int count){
	if(count==0){
		ww=max(searching1(a,n),ww);
		return;
	}
	for(int i=0;i<n;i++){
		a[i]++;
		count--;
		sea2(count);
		
		
		a[i]--;
		count++;
	}
	return;
}


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	
	if(m==0&&n<=5004){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		cout<<searching1(a,n );
		return 0;
	}
	for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
	sea2(m);
	cout<<ww;
	
	
	
	
	
	
	
	
	return 0;
}












