#include<bits/stdc++.h>
using namespace std;
long long a[20005];
struct s{
	int c,d;
}f[200005];
bool cmp(s a,s b){
	if(a.c==b.c){
		return a.d<b.d;
	}
	return a.c>b.c;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
	}
	if(m==2){
		long long maxa=LONG_LONG_MIN;
		for(int i=1;i<=n;i++){
		    for(int j=i+1;j<=n;j++){
		    	maxa=max(maxa,(a[i],a[j]));
		    }
	    }
	    cout<<maxa;
	}
	if(m==n){
		long long h=a[1];
		for(int i=2;i<=n;i++){
			h=(h&a[i]);
		}
		cout<<h;
	}
	else{
		for(int i=1;i<=n;i++){
			f[i].c=a[i];
			int s=a[i];
			while(s){
				if(s%2==0){
					f[i].d+=1;
					s/=2;
				}
				else{
					break;
				}
			}
		}
		sort(f+1,f+1+n,cmp);
		long long h=a[1];
		for(int i=1;i<=m;i++){
			h=(h&a[i]);
			//cout<<a[i]<<" ";
		}
		cout<<h;
	}
	return 0;
	
	
} 
