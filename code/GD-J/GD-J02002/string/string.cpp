#include<bits/stdc++.h>
using namespace std;
string w;
char w1[10000000];
struct a{
	string s;
	long long a;
	char b;
}q[10000000]; 
int main(){
	ios::sync_with_stdio(0);
	long long n,sum=0,l,r;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q[i].a>>q[i].b;
		for(int j=1;j<=q[i].a;j++){
			q[i].s+=q[i].b;
		}
	}for(int i=1;i<=n;i++){
		w+=q[i].s;
	}
	int ans=w.size();
	l=0;
 	r=ans;
 	if(ans%2==0){
 		for(int i=0;i<=ans/2;i++){
	 	if(l==r){
		 	break;
		}
 		if(w[l]!=w[r]){
 			sum++;
		 }
		 l++;
		 r--;
		 
	 }cout<<sum;
	 }else{
	 	for(int i=0;i<=ans/2;i++){
	 	if(l==r){
		 	continue;
		}
 		if(w[l]!=w[r]){
 			sum++;
		 }
		 l++;
		 r--;
	 	}cout<<sum;
	 }

	return 0;
}
