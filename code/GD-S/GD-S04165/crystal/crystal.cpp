#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[100005];
int cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,cnt=1;
	long long m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=1;i<n;i++){
		if(a[i]==a[i-1]){
			cnt++;
		}else{
			break;
		}
	}
	int s=0;
	while(s<m){
		for(int i=0;i<cnt;i++){
			a[i]++;
			s++;
			if (s>=m){
				break;
			}
		}
		if(a[cnt-1]==a[cnt]){
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
