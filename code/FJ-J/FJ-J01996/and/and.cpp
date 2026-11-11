#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[20005],bm;
bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bm=a[1];
	if(m==1){
		for(int i=1;i<=n;i++){
			bm=max(bm,a[i]);
		}	
	}
	if(m==2){
		sort(a+1,a+1+n,cmp);
		for(long long i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				bm=a[i];
			}
			else{
				bm=a[2];
			}
		}	
	}
	cout<<bm;
	return 0;
}
