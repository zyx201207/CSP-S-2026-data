#include<bits/stdc++.h>
using namespace std;
const int N=2.5e5;
//int n,a[N];
//暴力 
int a,n;
//char c[N];
//暴力 
char c;
long long sum;
//暴力 
string s;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	/*
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
	}int r=1,l=n;
	while(r<l){
		int k=min(a[i],a[l]);
		if(!c[i]==c[l]){
			sum+=k;
		}a[i]-=k;
		a[l]-=k;
		if(!a[i])i++;
		if(!a[l])l--;
	}cout<<sum;
	*/
	//暴力 
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}for(int i=0;i<(n+1)/2;i++){
		if(s[i]!=s[n-i+1])sum++;
	}cout<<sum;
	return 0;
}
