#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	long long n,m; 
    long long lie[100200];
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>lie[i];
	}
	
	sort(lie,lie+n);
	
	long long ans=0;
	long long couy=0;
    long long cmp=lie[1];
	for(long long i=0;i<n;i++){
		for(long long j=0;j<i+1;j++){
			if(lie[j]<cmp){
				m=m-(cmp-lie[j]);
				lie[j]=cmp;
			}
		}
		for(long long f=0;f<n;f++){
			if(lie[f]==cmp){
				couy++;
			}
		}
		ans=couy;
		couy=0;
		if(m<=0){
			cout<<ans;
			return 0;
		}
		cmp=lie[i+2];
	}
}

