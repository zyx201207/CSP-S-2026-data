#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a;
	cin>>a;
	long long N=100;
	long long s1[a+1];
	char s2[a+1];
	for(long long i=1;i<=a;i++){
		cin>>s1[i]>>s2[i];
	}long long k=1;
	for(int i=1;i<=a;i++){
		N+=s1[i];
	}
	char f[N+1],B[N+1];
	for(int i=1;i<=a;i++){
		for(int j=1;j<=s1[i];j++){
			f[k]=s2[i];
			k++;
			//cout<<k<<endl;
		}
	}for(int i=k;i>=1;i--){
		B[k-i+1]=f[i];
	}long long z=0;
	for(int i=1;i<=k-1;i++){
		if(B[i]!=f[i]){
			z++;
			//cout<<z<<endl;
		}
	}cout<<z-1;
	return 0;
}
