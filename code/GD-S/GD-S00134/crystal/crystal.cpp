/****
#include<bits/stdc++.h>
using namespace std;
//long long int dp[1000000000000000009];
long long int a[500008];
int n;
long long int m;
int l,r;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort (a,a+n);
	int mid = (n-1)/2;
	l=mid-1;r=mid+1;
	int ans;
	while (m>0&&l>=0){
		if (a[l]<a[mid]){
		a[l]++;
		if(m>0){
		m--;}
		}else{
			l--;
			ans++;
		}
		if(m==0&&l!=mid-1){
			ans++;
		}
	}
	
	for(int i=r;i<n;i++){
		if(a[i]==a[mid]){
		//	cout<<a[r]<<a[mid]
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
***/
/***********
#include<bits/stdc++.h>
using namespace std;
//long long int dp[1000000000000000009];
long long int a[500008];
int n,c;
long long int m;
int l,r,f;
int ans=1;
int b[500008];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long int pp=m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort (a,a+n);	
	////////////////////////////////////////////////	
	for(int k=1;k<n;k++){
		int mid = k;	
		l=mid-1;
	for(int i=0;i<=l;i++){
		b[i]=a[i];
	}
	//for(int i=0;i<=l;i++){
	//	cout<<b[i];	}
	//cout<<endl;
	///////////////////
	m=pp;
	while (m>0&&l>=0){
		if (b[l]<a[mid]){
		b[l]++;
		m--;
		}
		else
		{
			
			ans++;//cout<<b[l]<<'.'<<ans<<endl;
			l--;
		}
		c=max(ans,c);
	}	
	
	ans=1;
	}
	cout<<++c;
	return 0;
} 
*************/
#include<bits/stdc++.h>
using namespace std;
//long long int dp[1000000000000000009];
long long int a[500008];
int n,c;
long long int m;
int l,r,f;
int ans=1;
int b[500008];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long int pp=m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort (a,a+n);		
	for(int k=1;k<n;k++){
		int mid = k;	
		l=mid-1;
	for(int i=0;i<=l;i++){
		b[i]=a[i];
	}

	m=pp;
	while (m>0&&l>=0){
		if (b[l]<a[mid]){
		b[l]++;
		m--;
		}
		else
		{
			
			ans++;
			l--;
		}
	if(m==0&&l!=mid-1){
			ans++;
		}
		c=max(ans,c);
	}	
		for(int i=r;i<n;i++){
		if(a[i]==a[mid]){
			ans++;
		}
	}
	ans=1;
	}
	cout<<c;
	return 0;
} 
