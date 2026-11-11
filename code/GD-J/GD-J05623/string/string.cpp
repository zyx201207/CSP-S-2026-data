#include<bits/stdc++.h>
using namespace std;
char x1[200005];
long long x2[200005];
long long find1(long long n){ 
	long long cnt=0,ind=1;
	while(cnt<n){
		cnt+=x2[ind]; 
		ind++;
	}
	return ind-1;
}
long long find2(long long n){ 
	long long cnt=0,ind=n;
	while(cnt<n){
		cnt+=x2[ind]; 
		ind--;
	}
	return ind+1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long len=0,n,ans=0;
	cin>>n;
	string s=" ";
	for(long long i=1;i<=n;i++){
		long long ai;
		char ci;
		cin>>ai>>ci;
		len+=ai;
		for(long long j=1;j<=ai;j++){
			s+=ci;
		}
	//	x1[i]=ci;
	//	x2[i]=ai;
	}
	for(long long i=1;i<=len/2;i++){
		if(s[i]!=s[len-i+1]) ans++;
	}
	/*
	long long l=1,r=n,cnt=0;
	while(cnt<=len/2){
		if(x1[l]!=x2[r]){
			if(x2[l]>=x2[r]){
				ans+=x2[r];
				cnt+=x2[r];
				r--;
			}
		}
	}
	*/
	/*
	long long l=1;
	while(l<=len/2){	
	// 	cout<<l<<" "<<find1(l)<<" "<<find2(len-l+1)<<endl;	
		if(x1[find1(l)] != x1[find2(len-l+1)]){
		//	cout<<find1(l)<<" "<<find2(len-l+1)<<endl;
			ans++;
		}
		l++;
	}cout<<ans;
	*/
	cout<<ans;
	return 0;
}
