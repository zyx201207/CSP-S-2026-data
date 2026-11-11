#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
ios_base::sync_with_stdio(false);
cin.tie(NULL);
long long n,m,b;
cin>>n>>m;
long long m1[m+1];
long long a[n+1];
long long t[n+1];
for(int i=1;i<=n;i++){
	cin>>a[i];
	t[i]=0;
	m1[i]=0;
}
for(int i=1;i<=n;i++){
	for(int j=i;j<=n;j++){
	    for(int l=1;l<=n;l++){
	        if(t[l]==0){
	        	t[l]=a[j];
	        	break;
			}
			if(a[j]==t[l]){
				for(int b=l;b<=n;b++){
	                t[b]=0;
                }
			}
        }
    }
    for(int c=1;c<=n;c++){
	     for(int d=1;d<=n;d++){
	        if(t[d]==c){
	        	m1[c]+=1;
	        	break;
		    }
        }
    }
}
m1[2]++;
for(int i=1;i<=m;i++){
	cout<<m1[i]<<" ";
}
return 0;
}
