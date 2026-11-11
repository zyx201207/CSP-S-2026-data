#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	if(m==1){
		int maxn=0;
		for(int i=0;i<n;i++){
			if(a[i]>maxn){
				maxn=a[i];
			}
		}
		cout<<maxn;
		return 0;
	}
	if(n==m){
		long long ck=a[0];
	 for(int i=1;i<n;i++){
	 	ck=ck&a[i];
	 } 
	 cout<<ck;
	 return 0;
    } 
    if(m==2){
    	int cnp=0;
    	for(int i=0;i<n;i++){
    		for(int j=i+1;j<n;j++){
    			a[cnp]=a[i]&a[j];
    			cnp++;
			}
		}
		sort(a,a+cnp,cmp);
		cout<<a[0];
		return 0;
	}
	return 0;
}
