#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,s[10000],s1[1000],max=0,ji,er,s2[100000],sum=0,s3[100000];
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> s[i];
	}
	ji=s[0];
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(s[j]<s[j+1]){
				int t=s[j+1];
				s[j+1]=s[j];
				s[j]=t;
			}
		}
	}
	for(int i=0;i<n;i++){
		s3[i]=s1[i]=s[i];
	}
	for(int i=0;i<n;i++){
		er=0;
		while(s1[i]){
			if(s1[i]%2==1){
				er++;
			}
			s1[i]/=2;
		}
		s2[i]=er;
		if(er>max&&s[i]>ji){
			ji=s[i];
		}
	}
	for(int i=0;i<n;i++){
		if(s3[i]==ji){
			s3[i]=NULL;
			break;
		}
	}
	for(int i=0;i<m;i++){
		sum =ji&s3[i];
	}
	cout << sum;
}
