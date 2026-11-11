#include<bits/stdc++.h>
using namespace std;
int n;
long long b[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		cin>>c[i];
	}
	long long l=1,r=n;
	long long L=b[l],R=b[r];
	char l1=c[l],r1=c[r];
	while(l<r){
		if(L>R){
	    	if(l1!=r1){
	    		ans+=R;
	    	}
	    	L=L-R;
	    	r--;
			R=b[r];
			r1=c[r];
		}
		else if(R>L){
			if(l1!=r1){
				ans+=L;
			}
			R=R-L;
			l++;
			L=b[l];
			l1=c[l];
		}
		else{
			if(l1!=r1){
				ans+=L;
			}
			l++;
			r--;
			L=b[l];
			R=b[r];
			l1=c[l];
			r1=c[r];
		}
	}
	cout<<ans;
	
	return 0;
}
