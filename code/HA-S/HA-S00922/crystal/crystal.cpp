#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    long long n,m,a[200000],k=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int d=a[1]-a[0];
	for(int i=1;i<a[n-1];i+=d){
		if(m-i>=0){
			m-=i;
			k++;
		}else{
		    cout<<k;
		    return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
