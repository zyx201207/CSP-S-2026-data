#include <bits/stdc++.h>
using namespace std;
long long s[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s,s+n,cmp);
	if(m==1){
		cout<<s[0];
		return 0;
	}
	long long t=0;
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=1;j<=n;j++){
				if(s[i]&s[j]>=t){
				t=s[i]&s[j]; 
			}
		}
		
	}
	cout<<t;
	return 0;
}
else{
	cout<<100;
}
	return 0;
}
